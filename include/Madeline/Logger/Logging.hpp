#pragma once

#include <boost/interprocess/smart_ptr/shared_ptr.hpp>

#include <boost/lambda/lambda.hpp>	

#include <boost/date_time/posix_time/posix_time.hpp>


#include <boost/log/common.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/sinks.hpp>
#include <boost/log/sources/logger.hpp>

namespace MCAD
{
	namespace Logger
	{
		typedef boost::log::sinks::synchronous_sink< boost::log::sinks::text_file_backend > file_sink;
		class Logging
		{
		public:
			void init_logging();
			void init_file_collecting(boost::shared_ptr< file_sink > sink);
			void write_header(boost::log::sinks::text_file_backend::stream_type& file);
			void write_footer(boost::log::sinks::text_file_backend::stream_type& file);
		};
	}
} 