#pragma once

#include <exception>

namespace sdbusplus
{

namespace exception
{

/** Base exception class for all sdbusplus exceptions, including those created
 *  by the bindings. */
struct exception : public std::exception
{
    virtual const char* name() const noexcept = 0;
    virtual const char* description() const noexcept = 0;
};

/** base exception class for all errors generated by sdbusplus itself. */
struct internal_exception : public exception
{
};

/** Exception for when an invalid conversion from string to enum is
 *  attempted. */
struct InvalidEnumString final : public internal_exception
{
    static constexpr auto errName =
        "org.openbmc_project.sdbusplus.Error.InvalidEnumString";
    static constexpr auto errDesc =
        "An enumeration mapping was attempted for which no valid enumeration "
        "value exists.";
    static constexpr auto errWhat =
        "org.openbmc_project.sdbusplus.Error.InvalidEnumString: "
        "An enumeration mapping was attempted for which no valid enumeration "
        "value exists.";

    const char* name() const noexcept override
    {
        return errName;
    }

    const char* description() const noexcept override
    {
        return errDesc;
    }

    const char* what() const noexcept override
    {
        return errWhat;
    }
};

} // namespace exception

using exception_t = exception::exception;
using internal_exception_t = exception::internal_exception;

} // namespace sdbusplus