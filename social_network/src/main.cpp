#include <user_interface.hpp>

#include <iostream>
#include <cstdlib>

void DisplayLoggedUserMenu()
{
    int choice = -1;

    auto const & user = Server::GetCurrentUser();

    do
    {
        system("clear");

        UserInterface::DisplayBaseMenu();
        
        choice = Utils::SafeStringToInt(Utils::GetInput());

        system("clear");

        switch (choice)
        {
        case 1:
            user->Display();
            break;

        case 2:
            UserInterface::DisplayCreatePost();
            break;
        
        case 3:
            UserInterface::DisplayPosts();
            break;

        case 4:
            UserInterface::DisplayNewsFeed();
            break;

        case 5:
            UserInterface::DisplaySendMessage();
            break;

        case 6:
            UserInterface::DisplayMailbox();
            break;

        case 7:
            UserInterface::DisplayAddProfileBio();
            break;

        case 8:
            UserInterface::DisplayAddComment();
            break;

        case 9:
            if(UserInterface::DisplayDeleteAccount())
            {
                Utils::PauseTerminal();
                return;
            }
            break;

        default:
            break;
        }

        Utils::PauseTerminal();

    } while (choice != 0);
}

int main()
{
    int choice = -1;

    do
    {
        system("clear");

        UserInterface::DisplayStartMenu();

        choice = Utils::SafeStringToInt(Utils::GetInput());

        system("clear");

        switch (choice)
        {
        case 1:
            if(UserInterface::DisplayLoginMenu())
            {
                DisplayLoggedUserMenu();
                break;
            }
            break;

        case 2:
            UserInterface::DisplayRegistrationMenu();
            break;   
        
        case 3:
            UserInterface::DisplaySave();
            break;
        
        case 4:
            UserInterface::DisplayRecover();
            break;

        case 0:
            UserInterface::DisplayLogout();
            break;

        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

        Utils::PauseTerminal();
    }
    while (choice != 0);

    std::cout << "Program ended." << std::endl; 
    return 0;
}
