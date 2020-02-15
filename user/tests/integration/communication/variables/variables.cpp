#include "application.h"
#include "test.h"

#include <type_traits>
#include <limits>

namespace {

template<typename T>
typename std::enable_if<!std::is_integral<T>::value && !std::is_floating_point<T>::value, T>::type varVal() {
    return T();
}

template<typename T>
typename std::enable_if<std::is_integral<T>::value && std::is_signed<T>::value, T>::type varVal() {
    return std::numeric_limits<T>::min();
}

template<typename T>
typename std::enable_if<std::is_integral<T>::value && std::is_unsigned<T>::value, T>::type varVal() {
    return std::numeric_limits<T>::max();
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type varVal() {
    return std::numeric_limits<T>::max();
}

template<>
bool varVal<bool>() {
    return true;
}

template<>
const char* varVal<const char*>() {
    return "LlGqWwi6MhknxMW5Cbr62qBzYjrdXYxJiPKsnNOJ9dZli4WPOu22sr3Xc9r7yoni8Mkmb1KXrCyQI5J1V4JmWbhbrd5wJEOgUrsn";
}

template<>
String varVal<String>() {
    return "1n4m9ISRdZf7VlMP4RxrYiq0iVTwPKe1tD3maxwOCu3WnYJmngZmQM1wSChiP6twUyqozIs73lA7XGZBwgbGjGifa2cvAJ1Dodyw";
}

auto boolVar = varVal<bool>();
auto intVar = varVal<int>();
auto doubleVar = varVal<double>();
auto strVar = varVal<const char*>();
auto strObjVar = varVal<String>();

bool appThread = true;

template<typename T>
T varFn() {
    if (!application_thread_current(nullptr)) {
        appThread = false;
    }
    return varVal<T>();
}

template<typename T>
std::function<T()> makeVarStdFn() {
    return std::function<T()>(varFn<T>);
}

} // namespace

test(register_variables) {
    // Register variables
    Particle.variable("var_b", boolVar);
    Particle.variable("var_i", intVar);
    Particle.variable("var_d", doubleVar);
    Particle.variable("var_c", strVar);
    Particle.variable("var_s", strObjVar);
    // Register variable functions
    Particle.variable("fn_b", varFn<bool>);
    Particle.variable("fn_i8", varFn<int8_t>);
    Particle.variable("fn_u8", varFn<uint8_t>);
    Particle.variable("fn_i16", varFn<int16_t>);
    Particle.variable("fn_u16", varFn<uint16_t>);
    Particle.variable("fn_i32", varFn<int32_t>);
    Particle.variable("fn_u32", varFn<uint32_t>);
    Particle.variable("fn_f", varFn<float>);
    Particle.variable("fn_d", varFn<double>);
    Particle.variable("fn_c", varFn<const char*>);
    Particle.variable("fn_s", varFn<String>);
    Particle.variable("std_fn_i", makeVarStdFn<int>()); // std::function
    Particle.variable("std_fn_d", makeVarStdFn<double>()); // std::function
    Particle.variable("std_fn_c", makeVarStdFn<const char*>()); // std::function
    Particle.variable("std_fn_s", makeVarStdFn<String>()); // std::function
    // Connect to the cloud
    Particle.connect();
    waitUntil(Particle.connected);
    delay(3000);
}

test(check_current_thread) {
    // Verify that all variable requests have been processed in the application thread
    assertTrue(appThread);
}
