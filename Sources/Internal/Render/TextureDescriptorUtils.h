#pragma once

#include "Base/Vector.h"
#include "Render/TextureDescriptor.h"

namespace DAVA
{
/**
    \ingroup filesystem
    TextureDescriptorUtils is a helper class that provide operations for work with TextureDescriptor
 */

class FilePath;
class TextureDescriptorUtils final
{
public:
    /**
        Return true if texture descriptor file was created
    */
    static bool CreateDescriptor(const FilePath& imagePath);
    static bool CreateDescriptor(const FilePath& imagePath, std::unique_ptr<TextureDescriptor>& descriptor, bool descriptorChanged);

    /**
        Return true if texture descriptor file for cubemap faces was created
     */
    static bool CreateDescriptorCube(const DAVA::FilePath& texturePath, const DAVA::Vector<DAVA::FilePath>& imagePathes);

    /**
        Return true if texture descriptor file was changed according to passed imagePath
     */
    static bool UpdateDescriptor(const DAVA::FilePath& imagePath);
};
}
