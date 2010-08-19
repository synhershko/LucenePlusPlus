/////////////////////////////////////////////////////////////////////////////
// Copyright (c) 2009-2010 Alan Wright. All rights reserved.
// Distributable under the terms of either the Apache License (Version 2.0)
// or the GNU Lesser General Public License.
/////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Tokenizer.h"

namespace Lucene
{
	/// Emits the entire input as a single token.
	class LPPAPI KeywordTokenizer : public Tokenizer
	{
	public:
		KeywordTokenizer(ReaderPtr input);
		KeywordTokenizer(ReaderPtr input, int32_t bufferSize);
		KeywordTokenizer(AttributeSourcePtr source, ReaderPtr input, int32_t bufferSize);
		KeywordTokenizer(AttributeFactoryPtr factory, ReaderPtr input, int32_t bufferSize);
		
		virtual ~KeywordTokenizer();
		
		LUCENE_CLASS(KeywordTokenizer);
	
	protected:
		static const int32_t DEFAULT_BUFFER_SIZE;
		
		bool done;
		int32_t finalOffset;
		TermAttributePtr termAtt;
		OffsetAttributePtr offsetAtt;
	
	protected:
		void init(int32_t bufferSize);
	
	public:
		virtual bool incrementToken();
		virtual void end();
		virtual void reset();
	};
}