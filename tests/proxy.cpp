#include "proxy.h"

#include <unistd.h>
#include <cassert>

/**
 * This class is for testing purposes only and should not be altered
 */
Proxy::Proxy(const std::string& input) :
    m_stdout(STDOUT_FILENO),
    m_old_stdout(dup(m_stdout)),
    m_stdin(STDIN_FILENO),
    m_old_stdin(dup(m_stdin)) {

  interceptOut();
  interceptIn(input);
}

void Proxy::interceptOut() {
  char name_template[] = "/tmp/output_stream.XXXXXX";
  const int fake_output_fd = mkstemp(name_template);
  m_output_filename = name_template;

  fflush(nullptr);

  int ret = dup2(fake_output_fd, m_stdout);
  assert(ret == m_stdout);
  close(fake_output_fd);
}

void Proxy::interceptIn(const std::string& input) {
  char name_template[] = "/tmp/input_stream.XXXXXX";
  const int fake_input_fd = mkstemp(name_template);
  m_input_filename = name_template;

  int wrote = write(fake_input_fd, input.c_str(), input.length());
  assert(wrote == input.length());

  int ret = dup2(fake_input_fd, m_stdin);
  assert(ret == m_stdin);
  close(fake_input_fd);

  lseek(m_stdin, 0, SEEK_SET);
}

Proxy::~Proxy() {
  remove(m_output_filename.c_str());
  remove(m_input_filename.c_str());
}

static size_t get_file_size(FILE *file) {
  fseek(file, 0, SEEK_END);
  return static_cast<size_t>(ftell(file));
}

static std::string read_file(FILE *file) {
  const size_t file_size = get_file_size(file);
  char *const buffer = new char[file_size];

  size_t bytes_last_read = 0;
  size_t bytes_read = 0;

  fseek(file, 0, SEEK_SET);

  do {
    bytes_last_read = fread(buffer + bytes_read, 1, file_size - bytes_read, file);
    bytes_read += bytes_last_read;
  } while (bytes_last_read > 0 && bytes_read < file_size);

  const std::string content(buffer, bytes_read);
  delete[] buffer;

  return content;
}

std::string Proxy::output() {

  if (m_output_captured)
    return m_output;

  m_output_captured = true;
  connectOut();
  connectIn();

  FILE *const file = fopen(m_output_filename.c_str(), "r");
  m_output = read_file(file);
  fclose(file);
  return m_output;
}

void Proxy::connectIn() {
  connect(m_old_stdin, m_stdin);
  m_old_stdin = -1;
}

void Proxy::connectOut() {
  connect(m_old_stdout, m_stdout);
  m_old_stdout = -1;
}

void Proxy::connect(int old_fd, int fd) {
  if (old_fd != -1) {
    fflush(nullptr);
    dup2(old_fd, fd);
    close(old_fd);
  }
}

