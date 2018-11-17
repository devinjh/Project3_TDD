/*
  @file code_analysis.cpp

  Implementation of analysis requests
*/

#include "code_analysis.hpp"
#include "get_language_from_filename.hpp"
#include "xmlWrapper.hpp"

#include <string>

/** Generate source analysis XML based on the request
 * Content is wrapped with an XML element that includes the metadata
 * @param request Data that forms the request
 * @retval Source analysis request in XML format
 * @retval Empty string if invalid
 */
std::string formatAnalysisXML(const analysis_request& request) {

    // Code for Rules #1, 2, and 3
    if (request.disk_filename != "" || request.entry_filename != "" || request.option_filename != "")
    {
    	if (request.option_filename != "")
    	{
    		return request.option_filename;
    	}
    	if (request.disk_filename.find(".zip") != -1 || request.disk_filename.find(".gz") != -1)
    	{
    		if (request.entry_filename == "data" && request.disk_filename != "")
    		{
    			return request.disk_filename;
    		}
    		if (request.entry_filename == "")
    		{
    			return request.disk_filename;
    		}
    		return request.entry_filename;
    	}
    	if (request.disk_filename == "")
    	{
    		return request.entry_filename;
    	}
    	return request.disk_filename;
    }

    // Code for Rule #4
    //if (request.option)

    // wrap the content with a unit element
    xmlWrapper wrap("code", "http://mlcollard.net/code");
    wrap.startElement("unit");
    wrap.attribute("language", request.option_language);
    wrap.content(request.source_code);
    wrap.endElement();

    return wrap.xml();
}
