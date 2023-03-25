/*
 * error.hpp
 *
 * Error logging system
 */

#include <cstdio>

#define	ERRLOG_PRINT(error_type, ...)	{\
						::errlog::p##error_type##Start();\
						::std::fprintf(stderr, __VA_ARGS__);\
						::errlog::p##error_type##End();\
					}
#define	PERR(...)	ERRLOG_PRINT(Error, __VA_ARGS__)
#define	PINF(...)	ERRLOG_PRINT(Info, __VA_ARGS__) 

namespace errlog
{
	void pErrorStart();
	void pErrorEnd();
	void pInfoStart();
	void pEndStart();
}
