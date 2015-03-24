// libbarpp
// Dominik Cebula
// dominikcebula@gmail.com
// This file is part of the libbarpp project,
// licensed under GPLv2

#if defined(BARAPI_EXPORT)
#   define BARAPI   __declspec(dllexport)
#else
#   define BARAPI   __declspec(dllimport)
#endif
