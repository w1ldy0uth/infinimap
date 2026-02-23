#include <QApplication>
#include <QPushButton>
#include <QString>

#include "src/core/world/world_state.h"

int main(int argc, char* argv[])
{
    using namespace infinimap::core::world;

    WorldMetadata metadata;
    metadata.seed = 1337;
    metadata.name = "Demo world";
    metadata.worldWidth = 512;
    metadata.worldHeight = 256;
    metadata.formatVersion = 1;

    WorldState world = WorldState::createEmpty(metadata);
    std::string validationError;
    const bool isValid = world.isValid(&validationError);

    QApplication a(argc, argv);
    const QString buttonText = isValid
        ? QString("InfiniMap: WorldState ready (%1 cells)").arg(static_cast<qulonglong>(world.cellCount()))
        : QString("WorldState invalid: %1").arg(QString::fromStdString(validationError));
    QPushButton button(buttonText, nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();
}
