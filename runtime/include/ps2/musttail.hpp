#pragma once

#if defined(PS2_WEB_SAFARI26)
#define PS2_MUSTTAIL
#else
#define PS2_MUSTTAIL [[clang::musttail]]
#endif
