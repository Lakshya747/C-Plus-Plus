/**
 * @file
 * @brief Ground to ground projectile motion equation implementations
 * @details This program calculates various parameters of a projectile's
 * motion from ground level to ground level.
 * 
 * @author [Focusucof](https://github.com/Focusucof)
 */

#include <cassert>   // for assert()
#define _USE_MATH_DEFINES
#include <cmath>     // for std::pow(), std::sin(), std::cos()
#include <iostream>  // for IO operations

/**
 * @namespace physics
 * @brief Physics algorithms
 */
namespace physics {
/**
 * @namespace ground_to_ground_projectile_motion
 * @brief Functions for ground-to-ground projectile motion calculations
 */
namespace ground_to_ground_projectile_motion {

constexpr double GRAVITY = 9.81; // Standard gravity constant

/**
 * @brief Convert degrees to radians
 * @param degrees Angle in degrees
 * @returns Angle in radians
 */
double degrees_to_radians(double degrees) {
    return degrees * (M_PI / 180.0);
}

/**
 * @brief Calculate the time of flight
 * @param initial_velocity The starting velocity of the projectile
 * @param angle The launch angle in degrees
 * @param gravity The gravity constant (default is 9.81 m/s^2)
 * @returns Time the projectile is in the air
 */
template <typename T>
T time_of_flight(T initial_velocity, T angle, double gravity = GRAVITY) {
    double Viy = initial_velocity * std::sin(degrees_to_radians(angle)); // Vertical component
    return (2.0 * Viy) / gravity;
}

/**
 * @brief Calculate the horizontal distance traveled by the projectile
 * @param initial_velocity The starting velocity of the projectile
 * @param angle The launch angle in degrees
 * @param time The time the projectile is in the air
 * @returns Horizontal distance traveled
 */
template <typename T>
T horizontal_range(T initial_velocity, T angle, T time) {
    double Vix = initial_velocity * std::cos(degrees_to_radians(angle)); // Horizontal component
    return Vix * time;
}

/**
 * @brief Calculate the maximum height of the projectile
 * @param initial_velocity The starting velocity of the projectile
 * @param angle The launch angle in degrees
 * @param gravity The gravity constant (default is 9.81 m/s^2)
 * @returns Maximum height reached by the projectile
 */
template <typename T>
T max_height(T initial_velocity, T angle, double gravity = GRAVITY) {
    double Viy = initial_velocity * std::sin(degrees_to_radians(angle)); // Vertical component
    return (std::pow(Viy, 2)) / (2.0 * gravity);
}
}  // namespace ground_to_ground_projectile_motion
}  // namespace physics

/**
 * @brief Run self-tests to validate implementations
 */
static void test() {
    // Initial input variables
    double initial_velocity = 5.0;  // Starting velocity (m/s)
    double angle = 40.0;            // Launch angle (degrees)

    // Test 1: Time of Flight
    double expected_time_of_flight = 0.655; // Expected time (s)
    double flight_time_output = 
        std::round(physics::ground_to_ground_projectile_motion::time_of_flight(initial_velocity, angle) * 1000.0) / 1000.0;

    std::cout << "Projectile Flight Time (s)" << std::endl;
    std::cout << "Initial Velocity: " << initial_velocity << " m/s" << std::endl;
    std::cout << "Launch Angle: " << angle << " degrees" << std::endl;
    std::cout << "Expected Output: " << expected_time_of_flight << " s" << std::endl;
    std::cout << "Output: " << flight_time_output << " s" << std::endl;
    assert(flight_time_output == expected_time_of_flight);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // Test 2: Horizontal Range
    double expected_horizontal_range = 2.51; // Expected range (m)
    double horizontal_range_output = 
        std::round(physics::ground_to_ground_projectile_motion::horizontal_range(initial_velocity, angle, flight_time_output) * 100.0) / 100.0;

    std::cout << "Projectile Horizontal Range (m)" << std::endl;
    std::cout << "Initial Velocity: " << initial_velocity << " m/s" << std::endl;
    std::cout << "Launch Angle: " << angle << " degrees" << std::endl;
    std::cout << "Time of Flight: " << flight_time_output << " s" << std::endl;
    std::cout << "Expected Output: " << expected_horizontal_range << " m" << std::endl;
    std::cout << "Output: " << horizontal_range_output << " m" << std::endl;
    assert(horizontal_range_output == expected_horizontal_range);
    std::cout << "TEST PASSED" << std::endl << std::endl;

    // Test 3: Maximum Height
    double expected_max_height = 0.526; // Expected height (m)
    double max_height_output = 
        std::round(physics::ground_to_ground_projectile_motion::max_height(initial_velocity, angle) * 1000.0) / 1000.0;

    std::cout << "Projectile Max Height (m)" << std::endl;
    std::cout << "Initial Velocity: " << initial_velocity << " m/s" << std::endl;
    std::cout << "Launch Angle: " << angle << " degrees" << std::endl;
    std::cout << "Expected Output: " << expected_max_height << " m" << std::endl;
    std::cout << "Output: " << max_height_output << " m" << std::endl;
    assert(max_height_output == expected_max_height);
    std::cout << "TEST PASSED" << std::endl << std::endl;
}

/**
 * @brief Main function
 * @returns 0 on exit
 */
int main() {
    test();  // Run self-tests
    return 0;
}
