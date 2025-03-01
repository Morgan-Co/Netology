#include <iostream>
#include "html_render.h"

int main() {
  TextRenderer* text = new Text();
  TextRenderer* paragraph = new Paragraph(text);
  paragraph->render("Hello world");

  TextRenderer* reversed = new Reversed(text);
  reversed->render("Hello world");

  Link* link = new Link(text);
  link->render("netology.ru", "Hello world");

  delete text;
  delete paragraph;
  delete reversed;
  delete link;

  return 0;
}
