#include <vector>

#include <faker.hpp>

#include <cspec.hpp>

cspec_describe("uva::faker::sequence",
    describe("from_to",
        it("should generate from 0 to 10", [](){
            std::vector<int> firstTenNumbers = uva::faker::sequence::from_to(0, 10);

            expect(firstTenNumbers).to() << eq(std::vector<int>({
                0, 1, 2, 3, 4, 5, 6, 7, 8, 9
            }));
        })
    )
);