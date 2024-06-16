#pragma once
#if defined(PU_DEBUG) && (defined(PU_DESCRIBE) || defined(PU_SEPARATORS))
#include "iomanip"
#include "sstream"
#include "string"
#endif

namespace persistenceUtils {
	#if defined(PU_DEBUG) && defined(PU_DESCRIBE)
	inline std::string hexStr(const uint8_t *data, int len)
	{
		std::stringstream ss;
		ss << std::hex;
		for( int i(0) ; i < len; ++i )
			ss << std::setw(2) << std::setfill('0') << (int)data[i];
		return ss.str();
	}
	#endif

	#if defined(PU_DEBUG) && defined(PU_SEPARATORS)
	#include "util/InputStream.hpp"
	#include "util/OutputStream.hpp"

	static char l_testSeparator[] = { 'T', 'E', 'S', 'T' };
	static char l_vecSeparator[] = { 'V', 'E', 'C', 'T' };
	static char l_endSeparator[] = { 'E', 'N', 'D', 'E' };
	static char l_arrSeparator[] = { 'A', 'R', 'R', 'Y' };
	static char l_uMapSeparator[] = { 'M', 'A', 'P', 'U' };
	static char l_mapSeparator[] = { 'M', 'A', 'P', 'O' };
	static char l_strSeparator[] = { 'S', 'T', 'R', 'I' };
	static char l_uSetSeparator[] = { 'S', 'E', 'T', 'U' };
	static char l_setSeparator[] = { 'S', 'E', 'T', 'O' };

	void writeSeparator(std::string i_string, persistenceUtils::OutputStream& o_stream);
	void readSeparator(std::string o_string, persistenceUtils::InputStream& i_stream);

	#define SEPARATOR_O o_stream.write(l_testSeparator, 4);
	#define SEPARATOR_O_C(s) writeSeparator(#s, o_stream);
	#define VEC_SEPARATOR_O o_stream.write(l_vecSeparator, 4);
	#define ARR_SEPARATOR_O o_stream.write(l_arrSeparator, 4);
	#define UMAP_SEPARATOR_O o_stream.write(l_uMapSeparator, 4);
	#define MAP_SEPARATOR_O o_stream.write(l_mapSeparator, 4);
	#define STR_SEPARATOR_O o_stream.write(l_strSeparator, 4);
	#define USET_SEPARATOR_O o_stream.write(l_strSeparator, 4);
	#define SET_SEPARATOR_O o_stream.write(l_strSeparator, 4);
	#define SEPARATOR_O_END o_stream.write(l_endSeparator, 4);
	#define SEPARATOR_I i_stream.ignore(4);
	#define SEPARATOR_I_C(s) readSeparator(#s, i_stream);
	#define VEC_SEPARATOR_I i_stream.ignore(4);
	#define ARR_SEPARATOR_I i_stream.ignore(4);
	#define UMAP_SEPARATOR_I i_stream.ignore(4);
	#define MAP_SEPARATOR_I i_stream.ignore(4);
	#define STR_SEPARATOR_I i_stream.ignore(4);
	#define USET_SEPARATOR_I i_stream.ignore(4);
	#define SET_SEPARATOR_I i_stream.ignore(4);
	#define SEPARATOR_I_END i_stream.ignore(4);

	#else

	#define SEPARATOR_O
	#define SEPARATOR_O_C(s)
	#define VEC_SEPARATOR_O
	#define ARR_SEPARATOR_O
	#define UMAP_SEPARATOR_O
	#define MAP_SEPARATOR_O
	#define STR_SEPARATOR_O
	#define USET_SEPARATOR_O
	#define SET_SEPARATOR_O
	#define SEPARATOR_O_END
	#define SEPARATOR_I
	#define SEPARATOR_I_C(s)
	#define VEC_SEPARATOR_I
	#define ARR_SEPARATOR_I
	#define UMAP_SEPARATOR_I
	#define MAP_SEPARATOR_I
	#define STR_SEPARATOR_I
	#define USET_SEPARATOR_I
	#define SET_SEPARATOR_I
	#define SEPARATOR_I_END

	#endif
}