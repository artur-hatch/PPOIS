#pragma  once

#include <server.hpp>
#include "../utils/utils.hpp"

#include <regex>

class UserInterface
{
private:
public:
    static void DisplayStartMenu();
    static void DisplayRegistrationMenu();
    static bool DisplayLoginMenu();
    static void DisplaySave();
    static void DisplayRecover();
    static void DisplayLogout();

    static void DisplayBaseMenu();
    static void DisplayCreatePost();
    static void DisplayPosts();
    static void DisplayNewsFeed();
    static void DisplayAddComment();
    static void DisplaySendMessage();
    static void DisplayMailbox();
    static void DisplayAddProfileBio();
    static bool DisplayDeleteAccount();

    static void ShowFeed();
};