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

        request.disk_filename = "disk_filename.zip";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.entry_filename);

        request.disk_filename = "disk_filename.tar.gz";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.entry_filename);
    }

    // Rule #2
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

        // Test #
        request.disk_filename = "disk_filename.cpp";
        request.entry_filename = "entry_filename.cpp";
        assert(formatAnalysisXML(request) == request.disk_filename);
    }*/

    return 0;
}
