#include <vector>

#include <faker.hpp>

#include <cspec.hpp>

cspec_describe("uva::faker::lorem",
    describe("sentence",

        context("with min = 0",        
            it("should throw exception with min = 0", [](){
                expect([](){
                    uva::faker::lorem::sentence(0);
                }).to throw_a(std::runtime_error).with("error: invalid number of words");
            })
        )

        context("with min and max = 1",
            it("should generate one word with min and max = 1", [](){
                std::string sentence = uva::faker::lorem::sentence(1, 1);

                expect(sentence).to_not be_empty;
                expect((bool)isupper(sentence.front())).to eq(true);
                expect(sentence.back()).to eq('.');

                expect(sentence.find(' ')).to eq(std::string::npos);
            })
        )

        context("with min and max = 2",
            it("should generate two words with min and max = 2", [](){
                std::string sentence = uva::faker::lorem::sentence(2, 2);

                expect(sentence).to_not be_empty;
                expect((bool)isupper(sentence.front())).to eq(true);
                expect(sentence.back()).to eq('.');
                
                std::vector<std::string_view> words = uva::string::tokenize(std::string_view(sentence));
                expect(words.size()).to eq(2);
                //puts(uva::string::join(words, ','));
            })
        )

        context("with random min and max",
            it("should generate some words", [](){
                std::string sentence = uva::faker::lorem::sentence();

                expect(sentence).to_not be_empty;
                expect((bool)isupper(sentence.front())).to eq(true);
                expect(sentence.back()).to eq('.');
                
                std::vector<std::string_view> words = uva::string::tokenize(std::string_view(sentence));
                expect(words.size()).to be_between(4, 10);
            })
        )
    )
);