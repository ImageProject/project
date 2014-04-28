#ifndef USER_H
#define USER_H

#include "boost\serialization\access.hpp"
#include "boost/archive/tmpdir.hpp"
#include "boost/archive/tmpdir.hpp"
#include "boost/archive/text_iarchive.hpp"
#include "boost/archive/text_oarchive.hpp"
#include "boost/serialization/base_object.hpp"
#include "boost/serialization/utility.hpp"
#include "boost/serialization/list.hpp"
#include "boost/serialization/assume_abstract.hpp"
#include "boost/archive/xml_iarchive.hpp"
#include "boost/archive/xml_oarchive.hpp"
class User{
	public:
	friend class boost::serialization::access;
	std::string password;
	std::string login;
    bool New;
	User(){
		New = false;
	};
	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar << BOOST_SERIALIZATION_NVP(password);
		ar << BOOST_SERIALIZATION_NVP(login);
	}
};
#endif