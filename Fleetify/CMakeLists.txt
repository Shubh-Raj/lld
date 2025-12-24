cmake_minimum_required(VERSION 3.10)
project(Fleetify)

set(CMAKE_CXX_STANDARD 11)

# Add all source files
set(SOURCES
    main.cpp
    facade/CarRentalSystem.cpp
    managers/CarManager.cpp
    managers/ReservationManager.cpp
    models/Car.cpp
    models/Customer.cpp
    models/Reservation.cpp
    factories/SearchFactory.cpp
    factories/PaymentFactory.cpp
    strategies/PriceSearchStrategy.cpp
    strategies/TypeSearchStrategy.cpp
    strategies/AvailablitySearchStrategy.cpp
    strategies/UPIPayment.cpp
    strategies/NetBanking.cpp
)

add_executable(Fleetify ${SOURCES})
