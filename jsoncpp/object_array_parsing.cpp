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
        "version": "1.0",
        "item_list": [
          {
            "code": "A000001",
            "name": "Item #1",
            "desc": "Item Description"
          },
          {
            "code": "A000002",
            "name": "Item #2",
            "desc": "Item Description"
          },
          {
            "code": "A000003",
            "name": "Item #3",
            "desc": "Item Description"
          }
        ]
      }
    */
    std::string json_data = "{\"version\":\"1.0\",\"item_list\":[{\"code\":\"A000001\",\"name\":\"Item #1\",\"desc\":\"Item Description\"},{\"code\":\"A000002\",\"name\":\"Item #2\",\"desc\":\"Item Description\"},{\"code\":\"A000003\",\"name\":\"Item #3\",\"desc\":\"Item Description\"}]}";

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

    std::cout << "item_list: " << std::endl << std::endl;

    Json::Value jv_item_list = jv_root["item_list"];

    if ( !jv_item_list.isNull() && jv_item_list.isArray() )
    {
        Json::Value jv_item_code;
        Json::Value jv_item_name;
        Json::Value jv_item_desc;

        for ( int i = 0; i < jv_item_list.size(); ++i )
        {
            jv_item_code = jv_item_list[i]["code"];
            jv_item_name = jv_item_list[i]["name"];
            jv_item_desc = jv_item_list[i]["desc"];

            if ( !jv_item_code.isNull() && jv_item_code.isString() )
            {
                std::cout << ">> item[" << i << "] code: " << jv_item_code.asString() << std::endl;
            }

            if ( !jv_item_name.isNull() && jv_item_name.isString() )
            {
                std::cout << ">> item[" << i << "] name: " << jv_item_name.asString() << std::endl;
            }

            if ( !jv_item_desc.isNull() && jv_item_desc.isString() )
            {
                std::cout << ">> item[" << i << "] desc: " << jv_item_desc.asString() << std::endl;
            }

            std::cout << std::endl;
        }
    }

    return 0;
}