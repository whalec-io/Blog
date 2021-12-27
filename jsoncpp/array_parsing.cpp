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
        "integer_array": [
          12,
          44,
          92,
          104
        ],
        "string_array": [
          "A302PF",
          "DA09FQ",
          "120782"
        ]
      }
    */
    std::string json_data = "{\"integer_array\":[12,44,92,104],\"string_array\":[\"A302PF\",\"DA09FQ\",\"120782\"]}";

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

    int integer_value = 0;
    std::cout << "integer_array: " << std::endl;

    Json::Value jv_integer_array = jv_root["integer_array"];

    if ( !jv_integer_array.isNull() && jv_integer_array.isArray() )
    {
        std::cout << ">> size: " << jv_integer_array.size() << std::endl;

        for ( int i = 0; i < jv_integer_array.size(); ++i )
        {
            if ( jv_integer_array[i].isInt() )
            {
                integer_value = jv_integer_array[i].asInt();
                std::cout << ">> array[" << i << "]: " << integer_value << std::endl;
            }
        }
    }

    std::string string_value;
    std::cout << "string_array: " << std::endl;

    Json::Value jv_string_array = jv_root["string_array"];

    if ( !jv_string_array.isNull() && jv_string_array.isArray() )
    {
        std::cout << ">> size: " << jv_string_array.size() << std::endl;

        for ( int i = 0; i < jv_string_array.size(); ++i )
        {
            if ( jv_string_array[i].isString() )
            {
                string_value = jv_string_array[i].asString();
                std::cout << ">> array[" << i << "]: " << string_value << std::endl;
            }
        }
    }

    return 0;
}