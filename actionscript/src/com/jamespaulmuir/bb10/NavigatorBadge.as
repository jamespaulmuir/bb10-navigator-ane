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
	public final class NavigatorBadge
	{
		public static const NAVIGATOR_BADGE_SPLAT:NavigatorBadge = new NavigatorBadge(0);
		
		private var badge:int;
		
		public function NavigatorBadge(b:int)
		{
			badge = b;
		}
		
		public function valueOf():Object
		{
			return badge;
		}
		
		
	}
}