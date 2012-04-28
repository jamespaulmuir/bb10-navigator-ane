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
package com.jamespaulmuir.bb10
{
	import flash.external.ExtensionContext;

	public class Navigator
	{
		private static var context:ExtensionContext;
		
		public static const BPS_SUCCESS:int = 0;
		public static const BPS_FAILURE:int = -1;
		
		private static function extensionInstance():ExtensionContext
		{
			if(!context){
				context = ExtensionContext.createExtensionContext("com.jamespaulmuir.bb10.JPMNavigator", null);
			}
			return context;
		}
		
		public static function setBadge(badge:NavigatorBadge = null):Boolean
		{
			badge ||= NavigatorBadge.NAVIGATOR_BADGE_SPLAT;
			var result:Object = extensionInstance().call("setBadge", badge.valueOf());
			return result == BPS_SUCCESS ? true : false;
		}
		
		public static function clearBadge():Boolean
		{
			var result:Object = extensionInstance().call("clearBadge");
			return result == BPS_SUCCESS ? true : false;
		}
	}
	
	
}