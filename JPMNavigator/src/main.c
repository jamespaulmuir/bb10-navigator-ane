/*
 * Copyright (c) 2012 James Paul Muir
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "FlashRuntimeExtensions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/platform.h>
#include "bps/event.h"
#include "bps/navigator.h"
#include "bps/audiomixer.h"

void ExtensionInitializer(void** extDataToSet,
		FREContextInitializer* ctxInitializerToSet,
		FREContextFinalizer* ctxFinalizerToSet);
void ExtensionFinalizer();

void ContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx,
		uint32_t* numFunctionsToSet, const FRENamedFunction** functionsToSet);
void ContextFinalizer(FREContext ctx);

FREObject setBadge(FREContext ctx, void* functionData, uint32_t argc,
		FREObject argv[]);

FREObject setBadge(FREContext ctx, void* functionData, uint32_t argc,
		FREObject argv[]) {

	FREObject result;
	int32_t badge_t;

	if (argc != 1){
		FRENewObjectFromBool(BPS_FAILURE, &result);
		return result;
	}

	FREGetObjectAsInt32(argv[0], &badge_t);

	FRENewObjectFromInt32(
			navigator_set_badge(badge_t),
			&result);

	return result;
}

FREObject clearBadge(FREContext ctx, void* functionData, uint32_t argc,
		FREObject argv[]);

FREObject clearBadge(FREContext ctx, void* functionData, uint32_t argc,
		FREObject argv[]) {

	FREObject result;
	FRENewObjectFromInt32(navigator_clear_badge(), &result);
	return result;
}

/**
 * The runtime calls this method once when it loads an ActionScript extension.
 * Implement this function to do any initializations that your extension requires.
 * Then set the output parameters.
 *
 * @param extDataToSet
 *             A pointer to a pointer to the extension data of the ActionScript extension.
 *             Create a data structure to hold extension-specific data. For example, allocate
 *             the data from the heap, or provide global data. Set extDataToSet to a pointer
 *             to the allocated data.
 * @param ctxInitializerToSet
 *             A pointer to the pointer to the FREContextInitializer() function. Set
 *             ctxInitializerToSet to the FREContextInitializer() function you defined.
 * @param ctxFinalizerToSet
 *             A pointer to the pointer to the FREContextFinalizer() function. Set
 *             ctxFinalizerToSet to the FREContextFinalizer() function you defined. You can
 *             set this pointer to NULL.
 */
void ExtensionInitializer(void** extDataToSet,
		FREContextInitializer* ctxInitializerToSet,
		FREContextFinalizer* ctxFinalizerToSet) {
	*extDataToSet = NULL;
	*ctxInitializerToSet = &ContextInitializer;
	*ctxFinalizerToSet = &ContextFinalizer;
	bps_initialize();
}

/**
 * The runtime calls this function when it disposes of the ExtensionContext instance
 * for this extension context.
 */
void ExtensionFinalizer() {
	bps_shutdown();
}

/**
 * The runtime calls this method when the ActionScript side calls ExtensionContext.createExtensionContext().
 *
 * @param extData
 *             A pointer to the extension data of the ActionScript extension.
 * @param ctxType
 *             A string identifying the type of the context. You define this string as
 *             required by your extension. The context type can indicate any agreed-to meaning
 *             between the ActionScript side and native side of the extension. If your extension
 *             has no use for context types, this value can be Null. This value is a UTF-8
 *             encoded string, terminated with the null character.
 * @param ctx
 *             An FREContext variable. The runtime creates this value and passes it to FREContextInitializer().
 * @param numFunctionsToSet
 *             A pointer to a unint32_t. Set numFunctionsToSet to a unint32_t variable containing
 *             the number of functions in the functionsToSet parameter.
 * @param functionsToSet
 *             A pointer to an array of FRNamedFunction elements. Each element contains a pointer
 *             to a native function, and the string the ActionScript side uses in the ExtensionContext
 *             instance's call() method.
 */
void ContextInitializer(void* extData, const uint8_t* ctxType, FREContext ctx,
		uint32_t* numFunctionsToSet, const FRENamedFunction** functionsToSet) {
	char *temp = NULL;
	int i;

	// define an array of functions
	const char *functionNames[] = { "setBadge", "clearBadge", NULL };
	FREFunction functionPtrs[] = { setBadge, clearBadge, NULL };

	// count number of functions
	*numFunctionsToSet = 0;
	while (functionPtrs[*numFunctionsToSet] != NULL) {
		(*numFunctionsToSet)++;
	}

	FRENamedFunction *functionSet = calloc(*numFunctionsToSet,
			sizeof(FRENamedFunction));

	for (i = 0; i < *numFunctionsToSet; i++) {
		int bufferSize = sizeof(char) * (strlen(functionNames[i]) + 1);
		temp = (char*) malloc(bufferSize);
		strncpy(temp, functionNames[i], bufferSize);
		temp[strlen(functionNames[i])] = '\0';
		functionSet[i].name = (uint8_t*) temp;
		functionSet[i].functionData = NULL;
		functionSet[i].function = functionPtrs[i];
	}

	*functionsToSet = functionSet;
}

/**
 * The runtime calls this function when it disposes of the ExtensionContext instance for this extension context.
 *
 * @param ctx
 *             The FREContext variable that represents this extension context.
 */
void ContextFinalizer(FREContext ctx) {
}
