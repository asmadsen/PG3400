#ifndef C_ON_LINUX_HOME_EXAM_PROXY_H
#define C_ON_LINUX_HOME_EXAM_PROXY_H

#include <string>

/**
 * This class is for testing purposes only and should not be altered
 */
class Proxy {

public:
  explicit Proxy(const std::string&  input);
  ~Proxy();
  std::string output();

private:
  void interceptOut();
  void interceptIn(const std::string& input);

  std::string m_output;
  bool m_output_captured = false;
  int m_stdout;
  int m_old_stdout;
  int m_stdin;
  int m_old_stdin;
  std::string m_output_filename;
  std::string m_input_filename;

  static void connect(int old_fd, int fd);

  void connectOut();

  void connectIn();
};

#endif //C_ON_LINUX_HOME_EXAM_PROXY_H
