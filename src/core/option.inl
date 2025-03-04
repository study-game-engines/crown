/*
 * Copyright (c) 2012-2024 Daniele Bartolini et al.
 * SPDX-License-Identifier: MIT
 */

#include "core/option.h"

namespace crown
{
template<typename T>
inline Option<T>::Option(const T &default_val)
	: _value(default_val)
	, _changed(false)
{
}

template<typename T>
inline T &Option<T>::operator=(const T &val)
{
	_value = val;
	_changed = true;
	return *this;
}

template<typename T>
inline Option<T>::operator T() const
{
	return _value;
}

template<typename T>
inline Option<T>::operator T &()
{
	_changed = true;
	return _value;
}

template<typename T>
inline const T &Option<T>::value() const
{
	return _value;
}

template<typename T>
inline bool Option<T>::has_changed() const
{
	return _changed;
}

} // namespace crown
