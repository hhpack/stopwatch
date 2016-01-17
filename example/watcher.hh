<?hh //partial

/**
 * This file is part of hhpack\stopwatch.
 *
 * (c) Noritaka Horio <holy.shared.design@gmail.com>
 *
 * This source file is subject to the MIT license that is bundled
 * with this source code in the file LICENSE.
 */

namespace hhpack\stopwatch\example;

require_once __DIR__ . '/../vendor/autoload.php';

use hhpack\stopwatch\result\WatchedResult;
use hhpack\stopwatch\PerformanceWatcher;
use hhpack\stopwatch\TimeWatcher;
use hhpack\stopwatch\MemoryWatcher;

$watcher = PerformanceWatcher::fromItems([
  Pair { 'time', new TimeWatcher() },
  Pair { 'memory', new MemoryWatcher() }
]);

$watcher->start();
$watcher->stop();

$result = $watcher->result();
$texts = $result->mapWithKey(($key, $result) ==> {
  return sprintf("%s: %s", $key, (string) $result->diff());
})->values();

foreach ($texts as $text) {
  echo $text, PHP_EOL;
}
