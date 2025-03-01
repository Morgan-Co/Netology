#pragma once

#include <algorithm>
#include <string>
#include <iostream>

class TextRenderer {
public:
  virtual ~TextRenderer() = default;
  virtual void render(const std::string& text) const = 0;
};

class Text : public TextRenderer {
public:
  void render(const std::string& text) const override {
    std::cout << text;
  }
};

class TextDecorator : public TextRenderer {
protected:
  TextRenderer* wrappee;
public:
  TextDecorator(TextRenderer* wrappee) : wrappee(wrappee) {}
  void render(const std::string& text) const override {
    wrappee->render(text);
  }
};

class Paragraph : public TextDecorator {
public:
  Paragraph(TextRenderer* wrappee) : TextDecorator(wrappee) {}
  void render(const std::string& text) const override {
    std::cout << "<p>";
    wrappee->render(text);
    std::cout << "</p>" << std::endl;
  }
};

class Reversed : public TextDecorator {
public:
  Reversed(TextRenderer* wrappee) : TextDecorator(wrappee) {}
  void render(const std::string& text) const override {
    std::string reversed_text = text;
    std::reverse(reversed_text.begin(), reversed_text.end());
    wrappee->render(reversed_text);
    std::cout << std::endl;
  }
};

class Link : public TextDecorator {
public:
  Link(TextRenderer* wrappee) : TextDecorator(wrappee) {}
  void render(const std::string& url, const std::string& text) const {
    std::cout << "<a href=" << url << ">";
    wrappee->render(text);
    std::cout << "</a>" << std::endl;
  }
};
