#pragma once

#ifdef BINARYIODYN_EXPORTS
#define BINARYIO_API __declspec(dllexport)
#else
#define BINARYIO_API __declspec(dllimport)
#endif