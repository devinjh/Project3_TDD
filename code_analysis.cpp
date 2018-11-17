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

    // Code for Rule #5
    // Checks and makes sure that the default language is set, becasue this has the highest priority
    if (request.default_language != "")
    {
    	return request.default_language;
    }

    // Code for Rule #4
    // The next highest priority is the URLs. If either of those are provided, the code enters here
    if (request.option_url != "" || request.source_url != "")
    {
    	// The option URL has the highest priority and is returned with question if given
    	if (request.option_url != "")
    	{
    		return request.option_url;
    	}
    	// Otherwise, the source URL is returned
    	return request.source_url;
    }

    // Code for Rules #1, 2, and 3
    // If the filename of either the disk, entry, or option is provided, then the code enters here
    if (request.disk_filename != "" || request.entry_filename != "" || request.option_filename != "")
    {
    	// The option filename has the highest priority, so if it's provided, it's immediately returned
    	if (request.option_filename != "")
    	{
    		return request.option_filename;
    	}

    	// If the file is an archive file, then the code enters into here
    	if (request.disk_filename.find(".zip") != -1 || request.disk_filename.find(".gz") != -1)
    	{
    		// If the entry filename is simply "data" and the disk_filename is not blank, then
    		//the disk_filename must be returned
    		if (request.entry_filename == "data" && (request.disk_filename != "" && request.disk_filename != "-"))
    		{
    			return request.disk_filename;
    		}
    		// If the entry name is blank, then the disk filename is returned
    		if (request.entry_filename == "")
    		{
    			return request.disk_filename;
    		}
    		// Otherwise, the entry file is returned
    		return request.entry_filename;
    	}
    	// If the option filename is not provided, the file is not an archived file, and the
    	// disk file name is blank, then the entry file is returned
    	if (request.disk_filename == "")
    	{
    		return request.entry_filename;
    	}
    	// If the disk filename is a dash, than the entry filename is returned
    	else if (request.disk_filename == "-")
    	{
    		return request.entry_filename;
    	}
    	// Otherwise, the disk filename is returned
    	return request.disk_filename;
    }

    // wrap the content with a unit element
    xmlWrapper wrap("code", "http://mlcollard.net/code");
    wrap.startElement("unit");
    wrap.attribute("language", request.option_language);
    wrap.content(request.source_code);
    wrap.endElement();

    return wrap.xml();
}
