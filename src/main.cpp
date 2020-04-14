#include <cpr/cpr.h>
#include <string>
#include <vector>
#include <iostream>
#include "headers/json.hpp"
using json = nlohmann::json;

const std::string current_btc_price_uri = "http://api.coindesk.com/v1/bpi/currentprice.json";

const std::vector<std::string> supported_currencies {
    "EUR",
    "GBP",
    "USD"
};

void print_help()
{
    using namespace std;
    cout << "coinprice [EUR|USD|GBP]" << endl;
}

/**
 * Using coindesk REST API as data source.
 *
*/
int main(int argc, char** argv)
{
    std::string fiat = "EUR";
    // Process arguments.
    if (argc > 1) {
        if (std::string(argv[1]).compare("-h") == 0) {
            print_help();
            exit(0);
        }
        bool supported = false;
        for (auto it = supported_currencies.begin(); it != supported_currencies.end(); it++){
            if ( *it == argv[1]) {
                fiat = *it;
                supported = true;
            }
        }
        if (!supported) {
            std::cout << "Unsuported fiat." << std::endl;
            print_help();
            exit(-1);
        }
    }

    // Process request.
    auto btc_request = cpr::Get(cpr::Url{current_btc_price_uri});
    if (btc_request.status_code != 200) {
        std::cout << "Error processing request: " << btc_request.status_code <<  std::endl;
        exit(-1);
    }

    auto response = json::parse(btc_request.text.c_str());
    auto price = response["bpi"][fiat]["rate_float"];

    // Print BTC price.
    std::cout << price << std::endl;

    exit(0);
}