/*
  @file code_analysis_t.cpp

  Test program for analysis requests
*/

#include "code_analysis.hpp"

#include <string>
#include <cassert>

int main() {

    // Rule #1
    {
        analysis_request request;
        request.source_code = R"(if (a < b) a = b;)";
        request.disk_filename  = "";
        request.entry_filename  = "";
        request.option_filename = "";
        request.source_url       = "";
        request.option_url      = "";
        request.option_language = "C++";
        request.default_language = "";
        request.option_loc = -1;

        /*assert(formatAnalysisXML(request) ==
            R"(<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<code:unit xmlns:code="http://mlcollard.net/code" language="C++">
if (a &lt; b) a = b;
</code:unit>
)");
            )");*/

        // Test #1
        request.disk_filename = "disk_filename.cpp";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.disk_filename);

        // Test #2
        request.disk_filename = "disk_filename.zip";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.entry_filename);

        // Test #3
        request.disk_filename = "disk_filename.tar.gz";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.entry_filename);

        // Test #4
        request.disk_filename = "";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.entry_filename);

        // Test #5
        request.disk_filename = "disk_filename.zip";
        request.entry_filename = "";
        assert(formatAnalysisXML(request) == request.disk_filename);

        // Test #5
        request.disk_filename = "disk_filename.tar.gz";
        request.entry_filename = "";
        assert(formatAnalysisXML(request) == request.disk_filename);
    }

    // Rule #2
    {
        analysis_request request;
        request.source_code = R"(if (a < b) a = b;)";
        request.disk_filename  = "";
        request.entry_filename  = "";
        request.option_filename = "";
        request.source_url       = "";
        request.option_url      = "";
        request.option_language = "C++";
        request.default_language = "";
        request.option_loc = -1;

        // Test #1
        request.option_filename = "option_filename.cpp";
        request.disk_filename = "disk_filename.cpp";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.option_filename);

        // Test #2
        request.option_filename = "option_filename.cpp";
        request.disk_filename = "disk_filename.zip";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.option_filename);

        // Test #3
        request.option_filename = "option_filename.cpp";
        request.disk_filename = "disk_filename.tar.gz";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.option_filename);
    }

    // Rule #3
    {
        analysis_request request;
        request.source_code = R"(if (a < b) a = b;)";
        request.disk_filename  = "";
        request.entry_filename  = "";
        request.option_filename = "";
        request.source_url       = "";
        request.option_url      = "";
        request.option_language = "C++";
        request.default_language = "";
        request.option_loc = -1;

        // Test #1
        request.disk_filename = "disk_filename.cpp";
        request.entry_filename = "data";
        assert(formatAnalysisXML(request) == request.disk_filename);

        // Test #2
        request.disk_filename = "disk_filename.zip";
        request.entry_filename = "data";
        assert(formatAnalysisXML(request) == request.disk_filename);

        // Test #3
        request.disk_filename = "";
        request.entry_filename = "data";
        assert(formatAnalysisXML(request) == request.entry_filename);

        // Test #4
        request.option_filename = "option_filename.cpp";
        request.disk_filename = "disk_filename.tar.gz";
        request.entry_filename = "data";
        assert(formatAnalysisXML(request) == request.option_filename);

        // Test #5
        request.option_filename = "";
        request.disk_filename = "disk_filename.tar.gz";
        request.entry_filename = "data";
        assert(formatAnalysisXML(request) == request.disk_filename);

        // Test #6
        request.option_filename = "option_filename.cpp";
        request.disk_filename = "disk_filename.zip";
        request.entry_filename = "data";
        assert(formatAnalysisXML(request) == request.option_filename);

        // Test #7
        request.option_filename = "option_filename.cpp";
        request.disk_filename = "";
        request.entry_filename = "data";
        assert(formatAnalysisXML(request) == request.option_filename);

        // Test #8
        request.option_filename = "";
        request.disk_filename = "";
        request.entry_filename = "data";
        assert(formatAnalysisXML(request) == request.entry_filename);
    }

    // Rule #4
    {
        analysis_request request;
        request.source_code = R"(if (a < b) a = b;)";
        request.disk_filename  = "";
        request.entry_filename  = "";
        request.option_filename = "";
        request.source_url       = "";
        request.option_url      = "";
        request.option_language = "C++";
        request.default_language = "";
        request.option_loc = -1;

        // Test #1
        request.source_url = "source.url";
        request.option_url = "option.url";
        assert(formatAnalysisXML(request) == request.option_url);

        // Test #2
        request.source_url = "source.url";
        request.option_url = "";
        assert(formatAnalysisXML(request) == request.source_url);
    }

    // Rule #5
    {
        analysis_request request;
        request.source_code = R"(if (a < b) a = b;)";
        request.disk_filename  = "";
        request.entry_filename  = "";
        request.option_filename = "";
        request.source_url       = "";
        request.option_url      = "";
        request.option_language = "C++";
        request.default_language = "";
        request.option_loc = -1;

        // Test #1
        request.default_language = "python";
        assert(formatAnalysisXML(request) == request.default_language);
    }

    // Rule #6
    /*{
        analysis_request request;
        request.source_code = R"(if (a < b) a = b;)";
        request.disk_filename  = "";
        request.entry_filename  = "";
        request.option_filename = "";
        request.source_url       = "";
        request.option_url      = "";
        request.option_language = "C++";
        request.default_language = "";
        request.option_loc = -1;

        // Test #1
        request.default_language = "python";
        assert(formatAnalysisXML(request) == request.default_language);
    }*/

    // Rule #7
    {
        analysis_request request;
        request.source_code = R"(if (a < b) a = b;)";
        request.disk_filename  = "";
        request.entry_filename  = "";
        request.option_filename = "";
        request.source_url       = "";
        request.option_url      = "";
        request.option_language = "C++";
        request.default_language = "";
        request.option_loc = -1;

        // Test #1
        request.option_filename = "option_filename";
        request.disk_filename = "-";
        request.entry_filename = "entry_filename";
        assert(formatAnalysisXML(request) == request.option_filename);

        // Test #2
        request.option_filename = "";
        request.disk_filename = "-";
        request.entry_filename = "entry_filename";
        assert(formatAnalysisXML(request) == request.entry_filename);
    }

    return 0;
}
