#include <gtest/gtest.h>
#include "pricingutil.h"

TEST(sampleTest, sample) {
    EXPECT_EQ(4, 4);
}

TEST(PricingUtil, basic) {
    PricingUtil p;
    p.calcVal(1,1,1);
    EXPECT_NEAR(p.getVal(), 1.9, 1e-4);

    p.calcVal(p.getVal(), 0.05, 5);

    EXPECT_NEAR(p.getVal(), 9.025, 1e-4);
}

TEST(PricingUtil, edgeCases) {
    PricingUtil p;
    p.calcVal(1, 0, 1);
    EXPECT_NEAR(p.getVal(), 0.9, 1e-4);

    p.calcVal(1, -0.5, 2);
    EXPECT_NEAR(p.getVal(), 0.8, 1e-4);

    p.calcVal(-p.getVal(), 0.1, 1);
    EXPECT_NEAR(p.getVal(), -0.8, 1e-4);
}