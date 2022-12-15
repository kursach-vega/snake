#include "field_object.hpp"

#include <set>
#include <iostream>

Field_Object::Field_Object(short y, short x, TYPE_FIELD_OBJECT type) { 
	this->y = y;
	this->x = x;
	this->type = type;
	return ;
}

bool Field_Object::operator<(const Field_Object& other) const {
	if ( this->y == other.y ) { 
		return this->x < other.x;
	}
	return this->y < other.y;
}	

Field_Object make_Field_Object(short y, short x, TYPE_FIELD_OBJECT type) {
	return Field_Object(y, x, type);
}
