/************************************************************/
/*                        Dungeon Slasher                   */
/*                        by Kody Knight                    */
/*                        CSC 240                           */
/*                        Spring 2023                       */
/*                        Project #2                        */
/************************************************************/

using System;

//player data struct that I can call globally
struct PlayerStats
{
    public int Health;
    public int Damage;
    public string Weapon;
}


class Program
{
    //global variables to check if a room has been entered before
    public static bool[] Rooms = { false, false, false, false, false };
    //saves player input
    public static string input;
    //global struct of player data
    public static PlayerStats player;

    //main menu function
    /*
        allows the user to start the game of get a glimpse of the story
        returns nothing
    */
    static void Menu()
    {
        player.Health = 100;
        player.Damage = 5;
        player.Weapon = "Dagger";
        do
        {
            Console.WriteLine("Welcome to Dungeon Slayer!");
            Console.WriteLine("0: Quit Program");
            Console.WriteLine("1: Start Game");
            Console.WriteLine("2: Story");
            input = Console.ReadLine();
            Console.Clear();

            if (input == "0")
            {
                Console.WriteLine("Exiting Game.....");
                System.Environment.Exit(1);
            }
            if (input == "2")
            {
                Console.WriteLine("You have just woken up in a dungeon, this isn't your first time through the dungeon, or at ");
                Console.WriteLine("least you think so. The walls have a sense of familiarity to them, but you cant tell why. The ");
                Console.WriteLine("walls have tally marks, you don't know why but you feel the need to add another, something");
                Console.WriteLine("about it feels so instinctual. All you have is the gear on your back and anything else you ");
                Console.WriteLine("can find along the way.\n");
            }
        } while (input != "1");
        Console.Clear();
        RoomOne();
    }

    //starting room function
    /*
        returns nothing
        sets up the story and background while familiarizing the user with the game controls
    */
    static void RoomOne()
    {
        input = "";
        if (Rooms[0] == false)
        {
            Console.WriteLine("You wake up, the searing pain in your abdomen, like you had been impaled by something ");
            Console.WriteLine("but you were perfectly fine. Apon calming down you muster the strength to get up and face");
            Console.WriteLine("the world around you, the pain still lingering ever so slightly. As you take a look around you ");
            Console.WriteLine("can barely see, the room dimly lit with torches, and a lone barred window, you guessed it ");
            Console.WriteLine("were night out with no light coming through, the pitch black echoing eerily back at you like ");
            Console.WriteLine("nothing was there at all. You hear the sound of clanging in the dungeon, as if the sound of ");
            Console.WriteLine("metal hitting a cold wall.");
            Rooms[0] = true;
        }
        else
        {
            Console.WriteLine("The room you walked in looked familiar, as you look around you see");
            Console.WriteLine("a blood splatter. It takes you a second but you soon realize this ");
            Console.WriteLine("is the room you woke up in! The splatter right where you had woken up from!");
        }

        while (input != "1")
        {
            Console.WriteLine("\nwhere would you like to go next?");
            Console.WriteLine("1: north");
            input = Console.ReadLine();
            if (input != "1")
            {
                Console.WriteLine("That is not an option");
            }
        }
        Console.Clear();
        RoomTwo();
    }

    //Room two 
    /*
        Lore based room, no fighting, is a knife the player can pick up off the ground
    */
    static void RoomTwo()
    {
        input = "";
        if (Rooms[1] == false)
        {
            Console.WriteLine("You have yet to be greeted by anything, the sound of the metal clashing with the ground ");
            Console.WriteLine("getting louder, you see a weapon on the ground, the way it feels in your hand so familiar to ");
            Console.WriteLine("you, the weapon feels light enough to store in your belt.");
            Rooms[1] = true;
        }
        else
        {
            Console.WriteLine("You had already been here before, the echoing sound of the dungeon still persisted, like");
            Console.WriteLine(" you wernt quite alone.");
        }

        while (input != "1" && input != "2")
        {
            Console.WriteLine("\nwhere would you like to go next?");
            if (player.Weapon != "Knife" && player.Weapon != "Sword")
            {
                Console.WriteLine("0: pick up knife");
            }
            Console.WriteLine("1: North");
            Console.WriteLine("2: East");
            input = Console.ReadLine();
            Console.Clear();
            if (input == "0")
            {
                player.Weapon = "Knife";
                player.Damage = 10;
            }
            if (input != "1" && input != "2" && input != "0")
            {
                Console.WriteLine("That is not an option");
            }
        }
        if (input == "1")
        {
            Console.Clear();
            RoomSecret();
        }
        else
        {
            Console.Clear();
            RoomThree();
        }

    }

    //Room three 
    /*
        A lower level fight room connected to the boss and a optional fight room
        returns nothing
    */
    static void RoomThree()
    {
        input = "";
        int Health = 25;
        if (Rooms[3] == false)
        {
            Console.WriteLine("You enter the room, an enemy stands before you, just the sight of you makes him laugh, ");
            Console.WriteLine("oyur small size and torn up clothes makes him think you have no chance. Without thinking ");
            Console.WriteLine("he swings his club at you, you narrowly avoid taking the hit. Jumping back into a defensive ");
            Console.WriteLine("position.");
            Console.WriteLine("\nYou enter a fighting stance");
            Rooms[3] = true;
            while (Health > 0)
            {
                Console.WriteLine("You can see the enemy in front of you has " + Health + " Hp");
                Console.WriteLine("You have " + player.Health + " Hp");
                Console.WriteLine("What would you like to do?");
                Console.WriteLine("1: Attack");
                Console.WriteLine("2: Dodge");
                input = Console.ReadLine();
                Console.Clear();
                if (input == "2")
                {
                    Console.WriteLine("\nYou dodge out of the way of there attack, negatiting there damage");
                }
                else if (input == "1")
                {
                    Random rnd = new Random();
                    Console.WriteLine("Your attack hits for " + player.Damage);
                    Health -= player.Damage;
                    if (rnd.Next(2) % 2 == 0)
                    {
                        Console.WriteLine("There attack hits for 10 damage!");
                        player.Health -= 10;
                    }
                    else
                    {
                        Console.WriteLine("There attack misses!");
                    }
                }

            }
            input = "";
            Console.WriteLine("The enemy has been slane!");
        }
        else
        {
            Console.WriteLine("You have already entered this room before, the slane enemy lay on the ground beneath you.");
        }

        while (input != "1" && input != "2")
        {
            Console.WriteLine("Where would you like to go?");
            Console.WriteLine("1: North");
            Console.WriteLine("2: South");
            input = Console.ReadLine();
            Console.Clear();

            if (input == "1")
            {
                Console.Clear();
                RoomEnd();
            }
            else if (input == "2")
            {
                Console.Clear();
                RoomFour();
            }
            else
            {
                Console.WriteLine("That is not an option");
            }
        }
    }

    //Room four
    /*
        A upper level fight room to push the player a little more with stronger enemies preparing them for the final fight
        returns nothing
    */
    static void RoomFour()
    {
        input = "";
        if (Rooms[4] == false)
        {
            Rooms[4] = true;
            int Health = 75;
            Console.WriteLine("Upon entering the room you can hear the sound of snarling, the relatively dim nature of the ");
            Console.WriteLine("room providing your lurker with the perfect hiding spot. Out of the corner of your eye you ");
            Console.WriteLine("see it, 3 hungry wolves glaring at you, their mouths watering, their eyes looking red in the ");
            Console.WriteLine("light, you try to roll out of the way but one of them grazes you.");
            while (Health > 0)
            {
                Console.WriteLine("\nYou can see the wolves in front of you has " + Health + " Hp");
                Console.WriteLine("You have " + player.Health + " Hp");
                Console.WriteLine("What would you like to do?");
                Console.WriteLine("1: Attack");
                Console.WriteLine("2: Dodge");
                input = Console.ReadLine();
                Console.Clear();
                if (input == "2")
                {
                    Console.WriteLine("\nYou dodge out of the way of there attack, negatiting there damage");
                }
                else if (input == "1")
                {
                    Random rnd = new Random();
                    Console.WriteLine("Your attack hits for " + player.Damage);
                    Health -= player.Damage;
                    if (rnd.Next(2) % 2 == 0)
                    {
                        Console.WriteLine("The wolves attack hits for 15 damage!");
                        player.Health -= 15;
                    }
                    else
                    {
                        Console.WriteLine("There attack misses!");
                    }
                }

            }
            input = "";
            Console.WriteLine("The enemy has been slane!");
        }
        else
        {
            Console.WriteLine("The blood still fresh from your battle lays on the ground next to them");
            Console.WriteLine("They were bonded in life, and now in death, you let them rest regardless");
        }
        while (input != "1")
        {
            Console.WriteLine("Where would you like to go?");
            Console.WriteLine("1: North");
            input = Console.ReadLine();
        }
        Console.Clear();
        RoomThree();
    }

    //Secret room
    /*
        a side room with lore and a weapon that is stronger then anything previously, to help aid the player in beating the boss
    */
    static void RoomSecret()
    {
        input = "";
        if (Rooms[2] == false)
        {
            Console.WriteLine("A dying NPC, he’s been here so long, his legs slashed to bits, someone had wanted you not ");
            Console.WriteLine("to find him, or for him to not escape, the brickwall he was behind barely gave way. He was ");
            Console.WriteLine("shackled to the wall, \"p-please…\" he said, kicking towards you his weapon, he struggled to");
            Console.WriteLine("breath, as you got close to him you saw what was his final breath, kneeling before him, ");
            Console.WriteLine("paying respects. You shut his eyes as you say \"Thank you, sir.\"");
            Rooms[2] = true;
        }
        else
        {
            Console.WriteLine("You see the man stil laying there on the ground, you bow before him, honoring his");
            Console.WriteLine("Death as if he were one of your own.");
        }
        while (input != "1")
        {
            Console.WriteLine("What would you like to do?");
            if (player.Weapon != "Sword")
            {
                Console.WriteLine("0: pick up new Sword");
            }
            Console.WriteLine("1: South");
            input = Console.ReadLine();
            if (input == "0")
            {
                player.Weapon = "Sword";
                player.Damage = 15;
            }
            else if (input != "1")
            {
                Console.WriteLine("That is not an option");
            }
        }
        Console.Clear();
        RoomTwo();

    }

    //boss room
    /*
        boss room with two endings, returns nothing, the fight is the same mechanics as the last ones, excpet he hits harder and has more health
        increasing the challange for the player with base (non reguvinating) stats
    */
    static void RoomEnd()
    {
        input = "";
        int Health = 100;
        Console.WriteLine("Upon entering the room you see him, the beast of the dungeon. You memories come flooding back to you");
        Console.WriteLine("it was him, all him. Your suffering, your pain, he casued it. He stood there laughing before you");
        Console.WriteLine("\"back for me again little one? You think you really stand a chance now?\" he stood ready to fight you\n");
        while (Health > 0 && player.Health > 0)
        {
            Console.WriteLine("You can see him in front of you, he has " + Health + " Hp");
            Console.WriteLine("You have " + player.Health + " Hp");
            Console.WriteLine("What would you like to do?");
            Console.WriteLine("1: Attack");
            Console.WriteLine("2: Dodge");
            input = Console.ReadLine();
            Console.Clear();
            if (input == "2")
            {
                Console.WriteLine("\nYou dodge out of the way of his attack, negatiting his damage");
            }
            else if (input == "1")
            {
                Random rnd = new Random();
                Console.WriteLine("Your attack hits for ", player.Damage);
                Health -= player.Damage;
                if (rnd.Next(2) % 2 == 0)
                {
                    Console.WriteLine("The creatures attack hits for 20 damage!");
                    player.Health -= 20;
                }
                else
                {
                    Console.WriteLine("His attack misses!");
                    Console.WriteLine("He tried getting another swing off, enraged by you.");
                }
            }

        }
        input = "";
        if (Health < 0)
        {
            Console.WriteLine("\nWith a final swing of your blade the beast falls to his knees before you, struggling to breath, ");
            Console.WriteLine("gasping and wheezing for air, his eyes widened as he realized his fate, he had lost against you, ");
            Console.WriteLine("he had never lost a battle before now, he tried to stand up, defying his fate but he couldn't, he ");
            Console.WriteLine("own weapon falling out from under him as he used it as a crutch. His final sight was that of you, ");
            Console.WriteLine("standing in front of him, you knew his fate was sealed the moment he kneeled down before you. ");
            Console.WriteLine("You turn your back on him, knowing that the only mercy now was one of death, You walk out of ");
            Console.WriteLine("the dungeon, flicking the blood off your weapon, and holstering it. The beast would reach out to ");
            Console.WriteLine("you, now a silhouette on the rising sun, you never looked back, denying him of what little control ");
            Console.WriteLine("he had left of you.");
        }
        else
        {
            Console.WriteLine("\nAs you fall to the ground you can feel the hit of the beast, it's as if you were hit by a brick ");
            Console.WriteLine("wall. You reach for your stomach, barely able to stand, the pain making you lock up on the ");
            Console.WriteLine("spot, with what remaining strength you have you yell at the beast with all your might “This ");
            Console.WriteLine("isn't over!” your vision goes dark as you hear the clanging of your weapon hitting the ");
            Console.WriteLine("ground. You had lost yet felt it wasn't over quite yet, you knew you would see him again, ");
            Console.WriteLine("how many times you had done this song and dance was a different story, he looked so ");
            Console.WriteLine("familiar, why?");
        }
        Console.WriteLine("\nYou have reached the end of the game.");
        Console.WriteLine("Venture forth and follow your own adventure.");
        Console.WriteLine("Or simply replay this one!");
        Console.WriteLine("Exiting game...");
        System.Environment.Exit(1);
    }

    /*
        main function thats sole purpose is to run the main menu function
        returns nothing
    */
    public static void Main(string[] args)
    {
        Menu();
    }
}