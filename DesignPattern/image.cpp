#include <iostream>
#include <string>
#include <memory>

// Image Interface
class Image {
public:
  virtual ~Image() {}
  virtual std::string getData() = 0;
};

// RealImage Class (actual image)
class RealImage : public Image {
public:
  RealImage(const std::string& filename) {
    // Simulate image loading (e.g., network call)
    std::cout << "Loading image: " << filename << std::endl;
    // Load image data here (replace with your actual implementation)
    data_ = "Image data from " + filename;
  }

  std::string getData() override {
    return data_;
  }

private:
  std::string data_;
};

// ProxyImage Class (intermediary)
class ProxyImage : public Image {
public:
  ProxyImage(const std::string& filename) : filename_(filename) {}

  std::string getData() override {
    if (!real_image_) {
      real_image_ = std::make_shared<RealImage>(filename_);
    }
    return real_image_->getData();
  }

private:
  std::string filename_;
  std::shared_ptr<RealImage> real_image_;
};

// Client Code
int main() {
  // Create a proxy for an image
  ProxyImage image("image.jpg");

  // Access the image data through the proxy
  std::string data = image.getData();
  std::cout << "Image data: " << data << std::endl;

  // Access the image data again (cached)
  data = image.getData();
  std::cout << "Image data (cached): " << data << std::endl;

  return 0;
}
