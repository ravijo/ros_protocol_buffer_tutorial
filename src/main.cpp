/**
* main.cpp
* Author: Ravi Joshi
* Date: 2018/01/17
*/

#include <ros/ros.h>
#include "std_msgs/String.h"
#include "addressbook.pb.h"

int main(int argc, char** argv)
{
    GOOGLE_PROTOBUF_VERIFY_VERSION;

    ros::init(argc, argv, "node_name", ros::init_options::AnonymousName);
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::String>("protobuff_address_book", 100);

    tutorial::AddressBook address_book;

    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        tutorial::Person* person = address_book.add_people();

        std::stringstream person_name;
        person_name << "Person no. " << count;

        person->set_name(person_name.str());
        person->set_id(count);

        const tutorial::Person& my_person = address_book.people(count);

        std_msgs::String ros_msg;
        std::stringstream ss;
        ss << "Name: " << my_person.name() << ", id: " << my_person.id();
        ros_msg.data = ss.str();

        ROS_INFO("%s", ros_msg.data.c_str());

        pub.publish(ros_msg);
        ros::spinOnce();

        loop_rate.sleep();
        ++count;
    }

    return 0;
}
