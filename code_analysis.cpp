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

    // Code for Rule #1
    if (request.disk_filename != "")
    {
    	if (request.option_filename != "")
    	{
    		return request.option_filename;
    	}
    	if (request.disk_filename.find(".zip") != -1 || request.disk_filename.find(".gz") != -1)
    	{
    		if (request.entry_filename == "data")
    		{
    			return request.disk_filename;
    		}
    		else
    		{
    			return request.entry_filename;
    		}
    	}
    	else
    	{
    		return request.disk_filename;
    	}
    }
    // wrap the content with a unit element
    xmlWrapper wrap("code", "http://mlcollard.net/code");
    wrap.startElement("unit");
    wrap.attribute("language", request.option_language);
    wrap.content(request.source_code);
    wrap.endElement();

    return wrap.xml();
}
