cmake_minimum_required(VERSION 2.6)

project(ArbitrageCryptomonnaies)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(ArbitrageCryptomonnaies
    source/ArbitrageCryptomonnaies.cpp
    source/Budget.cpp
    source/Client.cpp
    source/Cours.cpp
    source/Devise.cpp
    source/Echange.cpp
    source/Monnaie.cpp
    source/Plateforme.cpp
    source/Projet.cpp
    source/Transaction.cpp)

target_include_directories(ArbitrageCryptomonnaies PUBLIC include)

install(TARGETS ArbitrageCryptomonnaies DESTINATION bin)
