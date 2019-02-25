import time
from datetime import datetime
import asyncio


async def print_message_periodical(interval_seconds: int, message: str):
    while True:
        print("%s-%s" % (datetime.now(), message))
        start = time.time()
        end = start + interval_seconds
        while True:
            await asyncio.sleep(0)
            now = time.time()
            if now >= end:
                break

if __name__ == "__main__":
    scheduler = asyncio.get_event_loop()
    scheduler.create_task(
        print_message_periodical(3, 'three')
    )
    scheduler.create_task(
        print_message_periodical(10, 'ten')
    )
    scheduler.run_forever()
