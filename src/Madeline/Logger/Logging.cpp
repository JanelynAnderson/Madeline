#include <include/Madeline/Logger/Logging.hpp>

namespace MCAD
{
	namespace Logger
	{
		void Logging::init_logging()
		{
			//make sink
			boost::shared_ptr< file_sink > sink(new file_sink (
				boost::log::keywords::file_name = "%Y%m%d_%H%M%S_%5N.txt",
				boost::log::keywords::rotation_size = 1048576
			));

			// set up where log files go
			init_file_collecting( sink );

			// scan past files
			sink->locked_backend()->scan_for_files();

			sink->set_formatter
			(
				boost::log::expressions::format("%1%: %2% >> %3%")
					% boost::log::expressions::attr< unsigned int >("RecordID")
					% boost::log::expressions::attr< boost::posix_time::ptime >("TimeStamp")
					% boost::log::expressions::c_ascii_decor[ boost::log::expressions::stream << boost::log::expressions::smessage]
			);

			// header and footer definitions
			sink->locked_backend()->set_open_handler
			(
				boost::lambda::_1 << "Header\n"
			);
			sink->locked_backend()->set_close_handler
			(
				boost::lambda::_1 << "Footer\n"
			);

			// add sink to core
			boost::log::core::get()->add_sink(sink);
		}

		void Logging::init_file_collecting(boost::shared_ptr< file_sink > sink)
		{
			sink->locked_backend()->set_file_collector(boost::log::sinks::file::make_collector(
				boost::log::keywords::target = "C:/Users/ander/AppData/Local/Madeline/logs",
				boost::log::keywords::max_size = 16 * 1024 * 1024,
				boost::log::keywords::min_free_space = 100 * 1024 * 1024,
				boost::log::keywords::max_files = 200
			));
		}

		void Logging::write_header(boost::log::sinks::text_file_backend::stream_type& file)
		{
			file << "<< MadelineCAD Log >>\nVersion 0.1\n";
		}

		void Logging::write_footer(boost::log::sinks::text_file_backend::stream_type& file)
		{
			file << "End Log\n Reason: %Reason%\n";
		}
	}
}
