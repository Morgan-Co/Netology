#include "Figure.h"
#include "InvalidFigure.h"

Figure::Figure() {
	name = "Figure";
	if (sides_count != 0) throw InvalidFigure("Ошибка создания фигуры. Причина: количество сторон должно быть 0");
}
