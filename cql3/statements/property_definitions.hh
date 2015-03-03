/*
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*
 * Copyright 2015 Cloudius Systems
 *
 * Modified by Cloudius Systems
 */

#ifndef CQL3_STATEMENTS_PROPERTY_DEFINITIONS_HH
#define CQL3_STATEMENTS_PROPERTY_DEFINITIONS_HH

#include "exceptions/exceptions.hh"
#include "core/print.hh"
#include "core/sstring.hh"

#include <unordered_map>
#include <map>

#include <boost/any.hpp>

namespace cql3 {

namespace statements {

#if 0
package org.apache.cassandra.cql3.statements;

import java.util.*;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import org.apache.cassandra.exceptions.SyntaxException;
#endif

class property_definitions {
protected:
#if 0
    protected static final Logger logger = LoggerFactory.getLogger(PropertyDefinitions.class);
#endif
    std::unordered_map<sstring, boost::any> _properties;

    property_definitions()
        : _properties{}
    { }
public:
    virtual void add_property(const sstring& name, sstring value) {
        auto it = _properties.find(name);
        if (it != _properties.end()) {
            throw exceptions::syntax_exception(sprint("Multiple definition for property '%s'", name));
        }
        _properties.emplace(name, value);
    }

    virtual void add_property(const sstring& name, const std::map<sstring, sstring>& value) {
        auto it = _properties.find(name);
        if (it != _properties.end()) {
            throw exceptions::syntax_exception(sprint("Multiple definition for property '%s'", name));
        }
        _properties.emplace(name, value);
    }

#if 0
    public void validate(Set<String> keywords, Set<String> obsolete) throws SyntaxException
    {
        for (String name : properties.keySet())
        {
            if (keywords.contains(name))
                continue;

            if (obsolete.contains(name))
                logger.warn("Ignoring obsolete property {}", name);
            else
                throw new SyntaxException(String.format("Unknown property '%s'", name));
        }
    }

    protected String getSimple(String name) throws SyntaxException
    {
        Object val = properties.get(name);
        if (val == null)
            return null;
        if (!(val instanceof String))
            throw new SyntaxException(String.format("Invalid value for property '%s'. It should be a string", name));
        return (String)val;
    }

    protected Map<String, String> getMap(String name) throws SyntaxException
    {
        Object val = properties.get(name);
        if (val == null)
            return null;
        if (!(val instanceof Map))
            throw new SyntaxException(String.format("Invalid value for property '%s'. It should be a map.", name));
        return (Map<String, String>)val;
    }

    public Boolean hasProperty(String name)
    {
        return properties.containsKey(name);
    }

    public String getString(String key, String defaultValue) throws SyntaxException
    {
        String value = getSimple(key);
        return value != null ? value : defaultValue;
    }

    // Return a property value, typed as a Boolean
    public Boolean getBoolean(String key, Boolean defaultValue) throws SyntaxException
    {
        String value = getSimple(key);
        return (value == null) ? defaultValue : value.toLowerCase().matches("(1|true|yes)");
    }

    // Return a property value, typed as a double
    public double getDouble(String key, double defaultValue) throws SyntaxException
    {
        String value = getSimple(key);
        if (value == null)
        {
            return defaultValue;
        }
        else
        {
            try
            {
                return Double.parseDouble(value);
            }
            catch (NumberFormatException e)
            {
                throw new SyntaxException(String.format("Invalid double value %s for '%s'", value, key));
            }
        }
    }

    // Return a property value, typed as an Integer
    public Integer getInt(String key, Integer defaultValue) throws SyntaxException
    {
        String value = getSimple(key);
        return toInt(key, value, defaultValue);
    }

    public static Integer toInt(String key, String value, Integer defaultValue) throws SyntaxException
    {
        if (value == null)
        {
            return defaultValue;
        }
        else
        {
            try
            {
                return Integer.valueOf(value);
            }
            catch (NumberFormatException e)
            {
                throw new SyntaxException(String.format("Invalid integer value %s for '%s'", value, key));
            }
        }
    }
#endif
};

}

}

#endif
