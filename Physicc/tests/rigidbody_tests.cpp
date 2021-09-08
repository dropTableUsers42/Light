#include "gtest/gtest.h"
#include "rigidbody.hpp"

class RigidBodyTests : public ::testing::Test
{
    protected:
        void SetUp() override
        {
            testBody = new Physicc::RigidBody(20, glm::vec3(1), 1.0f);
        }

        void TearDown() override
        {
            delete testBody;
        }

        Physicc::RigidBody* testBody;
};

TEST_F(RigidBodyTests, CheckVelocity)
{
    EXPECT_EQ(testBody->getVelocity(), glm::vec3(1.0f)) << "Unable to initialize velocity";
}

TEST_F(RigidBodyTests, ChangeVelocity)
{
    testBody->setVelocity(glm::vec3(4.0f));
    EXPECT_EQ(testBody->getVelocity(), glm::vec3(4.0)) << "Unable to change velocity";
}