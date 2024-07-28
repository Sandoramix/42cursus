#include "Brain.hpp"
#include <ostream>

static std::string generateIdea(int index)
{
	static const std::string ideasPool[] = {
		"Develop an AI for personal productivity boost",
		"Create a blockchain-based voting system now",
		"Design a smart home energy-saving device",
		"Invent a new method to recycle plastics   ",
		"Build an app for daily mental health check",
		"Launch a platform for remote team building",
		"Innovate eco-friendly packaging solutions ",
		"Start a community garden in urban areas   ",
		"Develop an AR app for home interior design",
		"Create a wearable for stress monitoring   ",
		"Build a drone delivery system for medicine",
		"Develop a language learning app with AI   ",
		"Invent a self-cleaning reusable bottle now",
		"Design an app to help with budgeting plans",
		"Create a platform for online skill trades ",
		"Launch a subscription box for local goods ",
		"Start a podcast on sustainable living tips",
		"Build a solar-powered portable charger now",
		"Develop an app to track carbon footprint  ",
		"Create a network for local volunteer work ",
		"Invent a gadget to help with sleep quality",
		"Design an ergonomic workspace furniture   ",
		"Build a mobile app for daily exercise tips",
		"Develop a digital art trading platform    ",
		"Create a pet care product line eco-friendly",
		"Launch an online course for coding basics ",
		"Start a digital detox retreat program now ",
		"Develop an AI for personalized book recs  ",
		"Invent a smart garden watering system now ",
		"Design a system for efficient waste sorting",
		"Create an app for plant care instructions ",
		"Build a platform for local farm produce   ",
		"Develop a VR app for historical tours now ",
		"Launch a service for meal prep delivery   ",
		"Invent a device for real-time language tr ",
		"Start an online mentorship program today  ",
		"Create a tool for tracking creative ideas ",
		"Build a database for DIY project plans    ",
		"Design a smartwatch for outdoor activities",
		"Develop an AI for personalized workouts   ",
		"Launch a green energy startup consultancy ",
		"Invent a smart recycling bin for homes    ",
		"Create a community for freelance creatives",
		"Build a platform for remote work resources",
		"Develop an app for mindfulness meditation ",
		"Start a service for sustainable fashion   ",
		"Design an AI for home organization tips   ",
		"Invent a portable air quality monitor now ",
		"Create an app to find local food markets  ",
		"Develop a program for senior citizen care ",
		"Build an online thrift store for clothing ",
		"Launch a fitness tracker with gamification",
		"Start a zero-waste grocery delivery service",
		"Design a smart thermostat with AI learning",
		"Invent a compact, portable water purifier ",
		"Develop an AI-driven music recommendation ",
		"Create a subscription box for art supplies ",
		"Build a peer-to-peer lending platform safe",
		"Start an app to organize group activities  ",
		"Launch a remote internship matching service",
		"Invent a high-efficiency solar panel now   ",
		"Create a language exchange social network  ",
		"Develop a wearable device for pet tracking ",
		"Build a VR application for virtual tourism ",
		"Design an AI for job application assistance",
		"Create a platform for digital art showcases",
		"Start a service for renting tools and gear ",
		"Develop a sustainable travel booking site  ",
		"Invent an app for personalized skincare    ",
		"Launch an online platform for DIY crafts   ",
		"Create an AI for personalized nutrition    ",
		"Develop a smart mirror for health tracking ",
		"Start an online community for book lovers  ",
		"Build an app for finding local events      ",
		"Invent a device for monitoring air quality ",
		"Create a service for eco-friendly moving   ",
		"Develop a cooking app with video tutorials ",
		"Launch an app to connect local musicians   ",
		"Build a platform for freelance educators   ",
		"Create a digital marketplace for artisans  ",
		"Develop an AI for home maintenance tips    ",
		"Start a virtual reality sports league now  ",
		"Invent a portable fitness tracking device  ",
		"Create an app for matching roommates       ",
		"Launch a service for plant-based meals     ",
		"Develop a tool for remote project management",
		"Start an online forum for tech enthusiasts ",
		"Create a subscription service for books    ",
		"Develop an AI for tracking personal goals  ",
		"Build a digital platform for job training  ",
		"Invent a wearable for monitoring hydration ",
		"Create an app for tracking study progress  ",
		"Launch a service for custom-made clothing  ",
		"Start a local farm-to-table food delivery  ",
		"Develop a tool for remote tutoring sessions",
		"Invent a device for reducing food waste    ",
		"Create an online marketplace for farmers   ",
		"Build a platform for sharing travel tips   ",
		"Develop an AI for pet care recommendations ",
		"Launch a virtual coworking space platform  ",
	};
	return ideasPool[index % Brain::IDEAS_COUNT];
}


Brain::Brain()
{
	std::cout << "[Brain][DefaultConstructor]" << std::endl;
	for (int i = 0; i < Brain::IDEAS_COUNT; i++)
		this->ideas[i] = generateIdea(i);
}

Brain::Brain(Brain &b)
{
	std::cout << "[Brain][CopyConstructor]" << std::endl;
	for (int i = 0; i < Brain::IDEAS_COUNT; i++)
		this->ideas[i] = b.getIdea(i);
}

Brain::~Brain()
{
std::cout << "[Brain][Destructor]" << std::endl;
}

Brain &Brain::operator=(Brain &b)
{
	if (&b == this){
		return *this;
	}
	for (int i = 0; i < Brain::IDEAS_COUNT; i++)
		this->ideas[i] = b.getIdea(i);
	return *this;
}

const std::string Brain::getIdea(int idx) const
{
	if (idx < 0 || idx >= Brain::IDEAS_COUNT){
		return "Placeholder for Index out of bounds";
	}
	return ideas[idx];
}
