/*==================================================================================
 Copyright (c) 2008, DAVA, INC
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of the DAVA, INC nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE DAVA, INC AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL DAVA, INC BE LIABLE FOR ANY
 DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 =====================================================================================*/

#ifndef __RESOURCEEDITORQT__MIMEDATAHELPER__
#define __RESOURCEEDITORQT__MIMEDATAHELPER__

#include "DAVAEngine.h"
#include <QMimeData>

class SceneEditor2;

namespace DAVA
{

class MimeDataHelper
{
public:
	
	static void ConvertFromMimeData(const QMimeData* mimeData, List<Entity*> &, SceneEditor2* sceneEditor );

	static bool IsMimeDataTypeSupported(const QMimeData* mimeData);
	
	static bool IsMimeDataTypeSupported(const String& mimeType);
	
	static void GetItemNamesFromMimeData(const QMimeData* mimeData, List<String>& nameList);
	
	static void ConvertToMimeData(List<FilePath>&, QMimeData* mimeData);

	static void ConvertToMimeData(List<Entity*>&, QMimeData* mimeData);
	
protected:

	static void ConvertQMimeDataFromSceneTree(const QMimeData* mimeData, List<Entity*>&,
											  SceneEditor2* sceneEditor = NULL);

	static void ConvertQMimeDataFromFilePath(const QMimeData* mimeData, List<Entity*>&,
											 SceneEditor2* sceneEditor = NULL);
	
	static void GetItemNamesFromSceneTreeMime(const QMimeData* mimeData, List<String> & nameList);
	
	static void GetItemNamesFromFilePathMime(const QMimeData* mimeData, List<String> & nameList);

	struct MimeHandler
	{
		DAVA::String format;
		void (*getNameFuncPtr) (const QMimeData* mimeData, List<String> & nameList);
		void (*convertFuncPtr) (const QMimeData* mimeData, List<Entity*> & nameList, SceneEditor2* sceneEditor);
		MimeHandler(DAVA::String _format,
					void (*_getNameFuncPtr) (const QMimeData* mimeData, List<String> & nameList),
					void (*_convertFuncPtr) (const QMimeData* mimeData, List<Entity*> & nameList,
					SceneEditor2* sceneEditor))
		{
			format = _format;
			getNameFuncPtr = _getNameFuncPtr;
			convertFuncPtr = _convertFuncPtr;
		}
	};
	
	const static MimeHandler mimeHandlerMap[];
};

};//DAVA nemaspace
#endif  /* defined(__RESOURCEEDITORQT__MIMEDATAHELPER__) */