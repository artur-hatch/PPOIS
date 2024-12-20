#include "user_interface.hpp"

void UserInterface::ShowFeed()
{
    std::cout << "======================================" << std::endl;
    std::cout << "           SilaNetwork feed           " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;
    
    for(auto const & post : Data::GetPosts())
    {
        post.second->Display();
    }
}

void UserInterface::DisplayStartMenu() {
    std::cout << "======================================" << std::endl;
    std::cout << "        Welcome to SilaNetwork!       " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "       Your Social World Awaits       " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    std::cout << "[1] Log In to Account" << std::endl;
    std::cout << "[2] Create New Account" << std::endl;
    std::cout << "[3] Log Out" << std::endl;
    std::cout << "[3] Save session" << std::endl;
    std::cout << "[4] Recover session" << std::endl;
    std::cout << std::endl;

    std::cout << "[0] Exit" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "Enter your choice: ";
}

void UserInterface::DisplayRegistrationMenu() {
    std::cout << "======================================" << std::endl;
    std::cout << "          Create an Account           " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "      Join Your Social Community      " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    std::string email, username, password;

    std::regex email_regex(R"((\w+)(\.{0,1})(\w*)@(\w+)\.(\w+))");
    bool valid_email = false;

    while (!valid_email) {
        std::cout << "Email: ";
        email = Utils::GetInput();

        if (std::regex_match(email, email_regex)) {
            valid_email = true;
        } else {
            std::cout << "Invalid email format. Please try again." << std::endl;
        }
    }

    std::cout << "Username: ";
    username = Utils::GetInput();
    std::cout << "Password: ";
    system("stty -echo");
    password = Utils::GetInput();
    system("stty echo");
    std::cout << std::endl;
    
    Server::CreateNewAccount(email, username, password);
}

bool UserInterface::DisplayLoginMenu() {
    std::cout << "======================================" << std::endl;
    std::cout << "                Login                 " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "        Connect with your friends     " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    std::string email, password;

    std::regex email_regex(R"((\w+)(\.{0,1})(\w*)@(\w+)\.(\w+))");
    bool valid_email = false;

    while (!valid_email) {
        std::cout << "Email: ";
        email = Utils::GetInput();

        if (std::regex_match(email, email_regex)) {
            valid_email = true;
        } else {
            std::cout << "Invalid email format. Please try again." << std::endl;
        }
    }

    std::cout << "Password: ";
    system("stty -echo");
    password = Utils::GetInput();
    system("stty echo");
    std::cout << std::endl;

    std::cout << "======================================" << std::endl;
    std::cout << "Attempting to log in..." << std::endl;
    std::cout << std::endl;

    if (Server::Login(email, password))
    {
        std::cout << "Login successful! Welcome back!" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Login failed. Please check your credentials." << std::endl;
        return false;
    }
}

void UserInterface::DisplaySave()
{
    std::cout << "======================================" << std::endl;
    std::cout << "            Save your history         " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    if(Data::Serialization())
    {
        std::cout << "Your history has been successfully saved." << std::endl;
    }
    else
    {
        std::cout << "Save error." << std::endl;
    }
}

void UserInterface::DisplayRecover()
{
    std::cout << "======================================" << std::endl;
    std::cout << "         Restore your history         " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    if(Data::Deserialization())
    {
        std::cout << "Your history has been successfully restored." << std::endl;
    }
    else
    {
        std::cout << "Restore error." << std::endl;
    }
}

void UserInterface::DisplayLogout() {
    std::cout << "======================================" << std::endl;
    std::cout << "                Goodbye!              " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    if (Server::Logout())
    {
        std::cout << "You have successfully logged out." << std::endl;
    }
    else
    {
        std::cout << "Logout failed. Please try again." << std::endl;
    }
}

void UserInterface::DisplayBaseMenu() {
    std::cout << "======================================" << std::endl;
    std::cout << "          Welcome to SilaNetwork      " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << "1. View Profile" << std::endl;
    std::cout << "2. Add Post" << std::endl;
    std::cout << "3. View your Posts" << std::endl;
    std::cout << "4. View News Feed" << std::endl;
    std::cout << "5. Send Message to User" << std::endl;

    auto const user = Server::GetCurrentUser();
    auto const & messages = user->GetMailbox()->GetMessages();
    if(!messages.empty())
    {
        size_t messagesAmount = messages.size();
        std::cout << "6. View the Mailbox [" << messagesAmount << "]" << std::endl;
    }
    else
    {
        std::cout << "6. View the Mailbox" << std::endl;
    }

    std::cout << "7. Add Account Description" << std::endl;
    std::cout << "8. Add Comment to Post" << std::endl;
    std::cout << "9. Delete your Account" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;
}

void UserInterface::DisplayCreatePost()
{
    std::cout << "======================================" << std::endl;
    std::cout << "            Create New Post           " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Enter the content of your post: " << std::endl;
    
    std::string content;
    content = Utils::GetInput();

    auto const & user = Server::GetCurrentUser();

    if (content.empty()) {
        std::cout << "Post content cannot be empty!" << std::endl;
    } else {
        user->CreatePost(content);
    }

    std::cout << std::endl;
}

void UserInterface::DisplayPosts()
{
    std::cout << "======================================" << std::endl;
    std::cout << "              Your Posts              " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    for(auto const & post : Server::GetCurrentUser()->GetPosts())
    {
        post.second->Display();
        std::cout << std::endl;
    }
}

void UserInterface::DisplayNewsFeed()
{
    std::cout << "======================================" << std::endl;
    std::cout << "              News Feed               " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    for(auto const & post : Data::GetPosts())
    {
        post.second->Display();
        std::cout << std::endl;
    }
}

void UserInterface::DisplayAddComment()
{
    std::cout << "======================================" << std::endl;
    std::cout << "          Add comment to post         " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Enter the comment: " << std::endl;

    std::string text;
    text = Utils::GetInput();

    std::cout << "Enter the id of the post: " << std::endl;

    std::string id;
    id = Utils::GetInput();

    auto const & userEmail = Server::GetCurrentUser()->GetEmail();
    auto const & posts = Data::GetPosts();

    auto it = posts.find(id);
    if(it != posts.end())
    {
        auto const & post = it->second;
        post->AddComment(text, userEmail);
    }
    else std::cout << "There is no post with the id " << id << "\n";
}

void UserInterface::DisplaySendMessage()
{
    std::cout << "======================================" << std::endl;
    std::cout << "              Send message            " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Enter the text of the message: " << std::endl;

    std::string message;
    message = Utils::GetInput();

    std::cout << "Enter the email of the recipient: " << std::endl;
    std::string recipientEmail;
    recipientEmail = Utils::GetInput();

    auto const sender = Server::GetCurrentUser(); 

    auto const & users = Data::GetUsers();

    auto it = users.find(recipientEmail);
    if(it != users.end())
    {
        auto const recipient = it->second;
        recipient->ReceiveMessage(message, sender);
    }
    else std::cout << "There is no user with the email " << recipientEmail << "\n";

    std::cout << std::endl << "Your message has been successfully sent.";
}

void UserInterface::DisplayMailbox()
{
    std::cout << "======================================" << std::endl;
    std::cout << "                Mailbox               " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    auto const user = Server::GetCurrentUser();

    auto const mailbox = user->GetMailbox();
    mailbox->Display();
}

void UserInterface::DisplayAddProfileBio()
{
    std::cout << "======================================" << std::endl;
    std::cout << "              Add your bio            " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    std::cout << "Enter the bio of your account: " << std::endl;
    
    std::string bio;
    bio = Utils::GetInput();

    auto const & user = Server::GetCurrentUser();

    if (bio.empty()) {
        std::cout << "Bio cannot be empty!" << std::endl;
    } else {
        user->SetBio(bio);
    }

    std::cout << std::endl;
}

bool UserInterface::DisplayDeleteAccount()
{
    std::cout << "======================================" << std::endl;
    std::cout << "            Account Deletion          " << std::endl;
    std::cout << "======================================" << std::endl;
    std::cout << std::endl;

    std::string confirmation;
    std::cout << "Are you sure you want to delete your account? (yes to confirm): ";
    confirmation = Utils::GetInput();

    if (confirmation != "yes") {
        std::cout << "Account deletion cancelled." << std::endl;
        return 0;
    }

    auto const user = Server::GetCurrentUser();

    std::string usernameConfirmation;
    std::string const expectedPhrase = "delete " + user->GetUsername();

    std::cout << "To confirm, type: " << expectedPhrase << std::endl;
    usernameConfirmation = Utils::GetInput();

    if (usernameConfirmation == expectedPhrase) {
        Server::DeleteAccount(user);
        std::cout << "Account deleted successfully." << std::endl;
        return 1;
    } else {
        std::cout << "Incorrect phrase. Account deletion cancelled." << std::endl;
        return 0;
    }
}
