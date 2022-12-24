#ifndef FIELD_OBJECT_HPP
#define FIELD_OBJECT_HPP

#include <cstddef>

enum class TYPE_FIELD_OBJECT {
	APPLE,
	NONE,
	SNAKE,
};

struct Field_Object {
    Field_Object() = default;
	Field_Object(short y, short x, TYPE_FIELD_OBJECT type);
	bool operator<(const Field_Object& other) const;
	short y;
	short x;
	TYPE_FIELD_OBJECT type;
};

Field_Object make_Field_Object(short y, short x, TYPE_FIELD_OBJECT type);

#endif
