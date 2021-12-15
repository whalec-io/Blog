#include <iostream>
#include <string>

#include "json/json.h"

int main()
{
    std::string json_data = "{\"integer\":1,\"floating_point\":1.0,\"boolean\":true,\"string\":\"whaleC\"}";

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

    // integer
    int integer_value = 0;
    Json::Value jv_integer_value = jv_root["integer"];

    if ( !jv_integer_value.isNull() && jv_integer_value.isInt() )
    {
        integer_value = jv_integer_value.asInt();
    }

    // floating point
    double double_value = 0.0;
    Json::Value jv_double_value = jv_root["floating_point"];

    if ( !jv_double_value.isNull() && jv_double_value.isDouble() )
    {
        double_value = jv_double_value.asDouble();
    }

    // boolean
    bool boolean_value = false;
    Json::Value jv_boolean_value = jv_root["boolean"];

    if ( !jv_boolean_value.isNull() && jv_boolean_value.isBool() )
    {
        boolean_value = jv_boolean_value.asBool();
    }

    // string
    std::string string_value;
    Json::Value jv_string_value = jv_root["string"];

    if ( !jv_string_value.isNull() && jv_string_value.isString() )
    {
        string_value = jv_string_value.asString();
    }

    std::cout << "integer_value: " << integer_value << std::endl;
    std::cout << "double_value: " << double_value << std::endl;
    std::cout << "boolean_value: " << boolean_value << std::endl;
    std::cout << "string_value: " << string_value << std::endl;

    return 0;
}