/**
 *
 * Copyright (c) 2021, whalec-io
 *
 * Distributed under MIT license, or public domain if desired and
 * recognized in your jurisdiction.
 *
 *    https://whalec.tistory.com / https://github.com/whalec-io
 *
 */

#include <iostream>
#include <string>

#include "json/json.h"

int main()
{
    /*
      {
        "header": {
          "version": "1.0",
          "request_id": 1
        },
        "data": {
          "code": "202112160900001",
          "name": "whaleC",
          "action": "open"
        }
      }
    */
    std::string json_data = "{\"header\":{\"version\":\"1.0\",\"request_id\":1},\"data\":{\"code\":\"202112160900001\",\"name\":\"whaleC\",\"action\":\"open\"}}";

    Json::CharReaderBuilder builder;
    Json::CharReader* reader = builder.newCharReader();

    Json::Value jv_root;
    std::string errors;

    bool parsing_successful = reader->parse(json_data.c_str(), json_data.c_str() + json_data.size(), &jv_root, &errors);

    if ( parsing_successful == false )
    {
        std::cout << "json parsing failed :" << std::endl;
        std::cout << errors << std::endl;

        return 0;
    }

    int request_id = 0;
    std::string version;
    std::string code;
    std::string name;
    std::string action;

    Json::Value jv_header = jv_root["header"];

    if ( !jv_header.isNull() && jv_header.isObject() )
    {
        Json::Value jv_version = jv_header["version"];
        Json::Value jv_reuqest_id = jv_header["request_id"];

        if ( !jv_version.isNull() && jv_version.isString() )
        {
            version = jv_version.asString();
        }

        if ( !jv_reuqest_id.isNull() && jv_reuqest_id.isInt() )
        {
            request_id = jv_reuqest_id.asInt();
        }
    }

    Json::Value jv_data = jv_root["data"];

    if ( !jv_data.isNull() && jv_data.isObject() )
    {
        Json::Value jv_code = jv_data["code"];  // same code: Json::Value jv_code = jv_root["data"]["code"];
        Json::Value jv_name = jv_data["name"];
        Json::Value jv_action = jv_data["action"];

        if ( !jv_code.isNull() && jv_code.isString() )
        {
            code = jv_code.asString();
        }

        if ( !jv_name.isNull() && jv_name.isString() )
        {
            name = jv_name.asString();
        }

        if ( !jv_action.isNull() && jv_action.isString() )
        {
            action = jv_action.asString();
        }
    }

    std::cout << "Header: " << std::endl;
    std::cout << ">> version: " << version << std::endl;
    std::cout << ">> request_id: " << request_id << std::endl;
    std::cout << "Data: " << std::endl;
    std::cout << ">> code: " << code << std::endl;
    std::cout << ">> name: " << name << std::endl;
    std::cout << ">> action: " << action << std::endl;

    return 0;
}