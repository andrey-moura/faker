#include <faker.hpp>

int uva::faker::random_integer(int min, int max)
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(min, max);

    return dis(gen);
}

double uva::faker::random_double(double min, double max)
{
    std::random_device rd;  // Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(min, max);

    return dis(gen);
}

std::string uva::faker::commerce::product()
{
    std::vector<std::string> products =
    {
        "LED Submersible Lights",
        "Scented Candles",
        "Beanies",
        "Portable Projector",
        "Bluetooth Speaker",
        "Smart Watch",
        "Temporary Tattoos",
        "Bookends",
        "Vegetable Chopper",
        "Neck Massager",
        "Ice Skates",
        "Back Cushion",
        "Portable Blender",
        "Nail Polish",
        "Wireless Phone Chargers",
        "Phone Lenses",
        "Shapewear",
        "Strapless Backless Bra",
        "Doormats",
        "Car Phone Holder",
        "Sweaters",
        "Wifi Repeater",
        "Laptop Accessories",
        "Posture Corrector",
        "Flexible Garden Hose",
        "One Piece Swimsuit",
        "Waterproof Eyebrow Liner",
        "Cat Massage Comb",
        "Breathable Mesh Running Shoes - Summer Product",
        "Portable Electric Ionic Hairbrush - Summer Product",
        "Beach Towels - Summer Product",
        "Baby Kids Water Play Mat - Summer Product",
        "Plush Blankets - Winter Product",
        "Winter Coats - Winter Product",
        "Socks - Winter Product",
        "Touchscreen Gloves - Winter Product",
        "Waterproof Pants - Winter Product",
        "Bear Claws - Spring Products",
        "Hiking Backpacks - Spring Products",
        "Minimalist Wallets - Spring Products",
        "Waterproof Shoe Cover - Autumn (Fall) Product",
        "Hooded Raincoats - Autumn (Fall) Product",
        "Laser Hair Removal Machines",
        "Portable Car Vacuum",
        "Baby Swings",
        "Matcha Tea",
        "Eyebrow Razor",
        "Seat Cushions",
        "Phone Tripod",
        "Portable Solar Panels",
    };

    return uva::faker::pick_one(products);
}

double uva::faker::commerce::price(double min, double max)
{
    return uva::faker::random_double(min, max);
}

// LOREM BEING

std::vector<std::string_view>& get_lorem_dictionary()
{
    static std::string_view lorem_text = R"~~~(
        Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ac orci phasellus egestas tellus rutrum tellus pellentesque eu tincidunt. Urna condimentum mattis pellentesque id nibh tortor id aliquet lectus. Ac tortor dignissim convallis aenean. Eget arcu dictum varius duis at consectetur lorem donec massa. Sodales ut eu sem integer vitae justo eget magna fermentum. Fermentum leo vel orci porta non pulvinar neque laoreet. Feugiat vivamus at augue eget arcu dictum varius. Consequat nisl vel pretium lectus quam id. Enim praesent elementum facilisis leo vel. Leo vel fringilla est ullamcorper eget nulla facilisi etiam. Quis hendrerit dolor magna eget est lorem ipsum dolor.
        Ante metus dictum at tempor commodo. Sit amet nulla facilisi morbi tempus iaculis urna id. Euismod quis viverra nibh cras pulvinar mattis nunc sed blandit. Ut placerat orci nulla pellentesque dignissim. Arcu odio ut sem nulla pharetra diam sit. Tellus orci ac auctor augue mauris. Augue interdum velit euismod in pellentesque massa placerat duis. Arcu ac tortor dignissim convallis aenean et tortor. Amet volutpat consequat mauris nunc congue nisi. Convallis convallis tellus id interdum velit. Sed felis eget velit aliquet sagittis id consectetur purus ut.
        Aliquam vestibulum morbi blandit cursus. Consequat semper viverra nam libero justo laoreet sit. Nisi vitae suscipit tellus mauris a diam maecenas. Tortor aliquam nulla facilisi cras. Cras pulvinar mattis nunc sed blandit. Varius morbi enim nunc faucibus a. Nunc non blandit massa enim nec dui nunc mattis. Purus sit amet volutpat consequat mauris nunc congue nisi vitae. Risus sed vulputate odio ut enim blandit. Placerat vestibulum lectus mauris ultrices eros in. Magna eget est lorem ipsum dolor sit amet consectetur. Ut enim blandit volutpat maecenas volutpat blandit aliquam. Mauris vitae ultricies leo integer malesuada nunc vel risus commodo. Vitae nunc sed velit dignissim sodales ut eu sem. Arcu odio ut sem nulla. Commodo viverra maecenas accumsan lacus.
        Adipiscing enim eu turpis egestas. Curabitur vitae nunc sed velit dignissim sodales ut eu. Varius sit amet mattis vulputate enim nulla aliquet porttitor. Eleifend quam adipiscing vitae proin. Id consectetur purus ut faucibus pulvinar elementum integer enim neque. Egestas dui id ornare arcu odio ut. Non arcu risus quis varius quam quisque id diam. Tellus in metus vulputate eu. Nisi vitae suscipit tellus mauris. Massa tincidunt nunc pulvinar sapien et ligula ullamcorper. Quis viverra nibh cras pulvinar mattis. Ullamcorper a lacus vestibulum sed arcu non odio. Purus semper eget duis at tellus at.
        Elementum eu facilisis sed odio morbi quis commodo odio aenean. Ultrices in iaculis nunc sed augue lacus viverra vitae. Aliquam malesuada bibendum arcu vitae. Quis viverra nibh cras pulvinar mattis nunc sed blandit. Ornare quam viverra orci sagittis eu volutpat odio facilisis. Sodales ut eu sem integer vitae justo eget magna. Id velit ut tortor pretium. Risus feugiat in ante metus dictum at tempor. Erat nam at lectus urna duis. Bibendum enim facilisis gravida neque convallis. Orci dapibus ultrices in iaculis nunc sed augue lacus viverra. Arcu non sodales neque sodales ut etiam sit amet nisl.
    )~~~";

    auto lorem_tokens = uva::string::tokenize(lorem_text);
    static std::vector<std::string_view> lorem_dictionary = uva::string::uniq(lorem_tokens);

    return lorem_dictionary;
}

std::vector<std::string_view>& get_lorem_words()
{
    std::vector<std::string_view>& dictionary = get_lorem_dictionary();
    
    static std::vector<std::string_view> lorem_words = uva::string::select(dictionary, [](const std::string_view& str) {
        return islower(str.front());
    });

    return lorem_words;
}

std::vector<std::string_view>& get_lorem_setence_begin()
{
    std::vector<std::string_view>& dictionary = get_lorem_dictionary();
    
    static std::vector<std::string_view> lorem_setence_begin = uva::string::select(dictionary, [](const std::string_view& str) {
        return isupper(str.front());
    });

    return lorem_setence_begin;
}

std::vector<std::string_view>& get_lorem_setence_end()
{
    std::vector<std::string_view>& dictionary = get_lorem_dictionary();
    
    static std::vector<std::string_view> lorem_setence_end = uva::string::select(dictionary, [](const std::string_view& str) {
        return str.back() == '.';
    });

    return lorem_setence_end;
}

std::string uva::faker::lorem::word()
{
    std::string word(pick_one(get_lorem_words()));

    if(word.ends_with(',') || word.ends_with('.')) {
        word.pop_back();
    }

    return word;
}

std::string uva::faker::lorem::sentence_begin()
{
    return std::string(pick_one(get_lorem_setence_begin()));
}

std::string uva::faker::lorem::sentence_end()
{
    return std::string(pick_one(get_lorem_setence_end()));
}

std::string uva::faker::lorem::sentence(int min_words, int max_words)
{
    int num_of_words = 0;

    if(max_words == 0) {
        max_words = 100;
    }

    if(!min_words) {
        throw std::runtime_error("error: invalid number of words");
    }
    else if(min_words == max_words) {
        num_of_words = min_words;
    } else {
        num_of_words = random_integer(min_words, max_words);
    }
    
    if(num_of_words < 1) {
        throw std::runtime_error("error: invalid number of words");
    }

    std::string sentence(sentence_begin());

    if(num_of_words == 1) {
        sentence.push_back('.');
    }
    else
    {
        for(size_t i = 0; i < num_of_words-2; ++i) {
            sentence.push_back(' ');
            sentence.append(word());
        }

        sentence.push_back(' ');
        sentence.append(sentence_end());
    }

    return sentence;
}

std::string uva::faker::lorem::paragraph(int setences)
{

}

// LOREM END