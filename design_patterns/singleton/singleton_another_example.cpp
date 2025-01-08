#include <iostream>

// deklarasi class Logger, sebagai wrapper
class Logger {
  protected:
    Logger ();

  public:
    static Logger& getInstance ();
    virtual std::string log (std::string message) = 0;
};

// definisi class Logger untuk Windows
class WindowLogger : public Logger {
  public:
    std::string log(std::string message) override {
      // lakukan Windows spesific task

      return "[WINDOWS] INFO: " + message;
    }
};

// definisi class Logger untuk Unix
class UnixLogger : public Logger {
  public:
    std::string log(std::string message) override {
      // lakukan Unix spesific task
      
      return "[UNIX] INFO: " + message;
    }
};

// definisi class Logger
Logger::Logger () = default;
Logger& Logger::getInstance () {
  // lazy intialize (di inisialisasi saat fungsi dipanggil pertama kali)
#ifdef _WIN32 
  static WindowLogger* instance = new WindowLogger();       
#else
  static UnixLogger* instance = new UnixLogger();
#endif // _WIN32
  return *instance;
}

int main () {
  std::cout << "Logging menggunakan `Logger` class: \n";
  std::cout << "\t" << Logger::getInstance().log("Hello World") << std::endl;
}
