#pragma once
#ifdef LEAVER_EXPORTS
#define LEAVER_API __declspec(dllexport)
#else
#define LEAVER_API __declspec(dllimport)
#endif // LEAVER_EXPORTS

#include <string>

namespace Leaver {
	class Leaver {
	public:
		LEAVER_API void leave(std::string name);
	};
}
