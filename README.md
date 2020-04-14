# COINPRICECPP

## What is this?

It is a toy project to experiment with [JSON](https://github.com/nlohmann/json) and [HTTP requests](https://github.com/whoshuu/cpr) on C++14.

## What does it do?
Build it:
`mkdir build && cd build && cmake .. && make`

Usage:
`coinprice [EUR|USD|GBP]`

I tried to imitate the KISS philosophy used in traditional UNIX tools.

You call the command, by default it returns the current bitcoin price from coindesk in Euros, because that is what I have where we live.

USD and GBP are also supported.

### Supported coins

For now it only supports BTC.

## What I learned
- Features in modern C++ (C++11)
- [JSON  for Modern C++](https://github.com/nlohmann/json)
- [C++ Requests: Curl for People](https://github.com/whoshuu/cpr)

_The question remains, how far can I go with Modern C++ until finding the complexity issues that interpreted languages promise to solve?_