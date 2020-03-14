#include <iostream>
#include <memory>

// Product
class Window{ 
  public: 
    virtual std::shared_ptr<Window> clone() = 0; 
};

// Concrete Products 
class DefaultWindow: public Window {
  public:
    DefaultWindow() {
      std::cout << "DefaultWindow" << std::endl;
    }
  private:
    std::shared_ptr<Window> clone() override { 
      return std::make_shared<DefaultWindow>();
    } 
};

class FancyWindow: public Window {
  public:
    FancyWindow() {
      std::cout << "FancyWindow" << std::endl;
    }
  private:
    std::shared_ptr<Window> clone() override { 
      return std::make_shared<FancyWindow>();
    } 
};

// Concrete Creator or Client
auto getNewWindow(std::shared_ptr<Window> oldWindow) { 
  return oldWindow->clone();
}
  
int main() {

  std::shared_ptr<Window> defaultWindow = std::make_shared<DefaultWindow>();
  std::shared_ptr<Window> fancyWindow = std::make_shared<FancyWindow>();
  
  auto defaultWindow1 = getNewWindow(defaultWindow);
  auto fancyWindow1 = getNewWindow(fancyWindow);
  
}
